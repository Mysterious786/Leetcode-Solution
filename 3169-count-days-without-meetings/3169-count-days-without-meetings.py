class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        if not meetings:
            return days  # No meetings, so all days are available.

        # Sort meetings by start time to process them in order.
        meetings.sort()

        ans = 0
        start, end = meetings[0]  # Initialize with the first meeting.

        for i in range(1, len(meetings)):
            current_start, current_end = meetings[i]

            # If current meeting starts after the previous one ends, count the previous interval.
            if current_start > end:
                ans += (end - start + 1)
                start = current_start  # Update the start to the current meeting.
                end = current_end      # Update the end to the current meeting.
            else:
                # There is an overlap, so merge intervals.
                end = max(end, current_end)

        # Add the last interval.
        ans += (end - start + 1)

        return days - ans  # Subtract the total number of meeting days from total days.

        
        