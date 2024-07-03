class Solution {
    public int wateringPlants(final int[] plants, final int capacity) {
        int count = 0, current = capacity;

        for(int i = 0; i < plants.length; ++i) {
            final int plant = plants[i];

            if(current < plant) {
                count += i * 2;
                current = capacity;
            }

            current -= plant;
            count++;
        }

        return count;
    }
}