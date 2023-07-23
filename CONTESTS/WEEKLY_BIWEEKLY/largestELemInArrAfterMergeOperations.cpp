//weekly 355
/* QUESTION => if nums[i] <= nums[i+1] replace nums[i+1] = sum and remove arr[i]
=> so we're reducing the len of the array => return value of largest elem that you can obtain in the array */
int mod = 1e9 + 7;
long long maxArrayValue(vector<int>& arr) {
    int n = arr.size();
    vector<double> nums (n, 0);
    for(int i = 0; i < n; i++) {
        nums[i] = arr[i];
    }
    
    long long largest = nums[0];//dec arr > same && inc arr > changes
    int i = nums.size()-2;
    
    while(i >= 0) {
        if(nums.size() == 1) {
            //below if > runtime error
            break;//bcz largest is already updated 
        }
        if(nums[i] <= nums[i+1]) {
            nums[i+1] = nums[i] + nums[i+1];
            
            if(nums[i+1] > largest) largest = nums[i+1];
            
            nums.erase(nums.begin() + i);
            
            i = nums.size()-2;
            continue;
        }
        //if above condn fails dec i
        i--;
    }
    //i < 0 then we have largest
    return largest;
}
