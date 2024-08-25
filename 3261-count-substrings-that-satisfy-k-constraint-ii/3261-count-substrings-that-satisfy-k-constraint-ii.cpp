class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) 
    {
        int n = s.size();
        vector<long long> answer;
        vector<long long> previous_index_till_valid(n);
        vector<long long> prefix_sum_of_valid_strings(n);
        int left_pointer = 0;
        int zeros=0;
        int ones=0;
        for(int right_pointer =0; right_pointer <n; right_pointer++)
        {
            if(s[right_pointer]=='1') 
                ones++;
            else 
                zeros++;

            while(zeros > k && ones > k)
            {
                if(s[left_pointer]=='1') 
                    ones--;
                else 
                    zeros--;
                left_pointer++;
            }

            previous_index_till_valid[right_pointer] = left_pointer;
        } // n

        prefix_sum_of_valid_strings[0]=1;

        for(int i = 1; i<n; i++)
        {
            long long length_of_valid_substrings = (i-previous_index_till_valid[i]+1);
            prefix_sum_of_valid_strings[i] = prefix_sum_of_valid_strings[i-1] + length_of_valid_substrings;
        } // n

        for(auto &q : queries) // q
        {
            long long l = q[0];
            long long r = q[1];

            long long result = 0;
            long long first_position = r+1;

            while(l<=r)
            {
                long long mid = (l+r)/2;
                if(previous_index_till_valid[mid]>=q[0])
                {
                    first_position = mid;
                    r = mid-1;
                } 
                else l = mid+1;
            } // logn

            
            if(first_position<=q[1])
            {
                result += prefix_sum_of_valid_strings[q[1]];
                if(first_position>0)
                result -= prefix_sum_of_valid_strings[first_position-1];
            } // 1

            long long difference = first_position - q[0];
            result += (difference)*(difference+1)/2; // 2
            
            answer.push_back(result);
        }
        return answer;
    }
    // tc - O(qlogn) - O(10^5*log(10^5))
    // sc - O(n)
};