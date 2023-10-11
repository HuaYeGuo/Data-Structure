public class Binary_Search{
    public static void main(String[] args) {
        int[] arr = {1, 3, 4, 6, 7, 8, 10, 11, 13, 15};
        System.out.println(Search(arr,11));
    }
    public static int Search(int[]arr,int target) {
        int left = 0,right = arr.length - 1;
        while (left <= right){
            int mid = (left + right) <<< 1;
            if (arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        return -1;
    }
}
