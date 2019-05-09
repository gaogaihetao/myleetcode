int check(vector<int> &nums1, vector<int> &nums2,int n1,int n2) {
    if(n1==0||n2==nums2.size()) {
        if(nums1[n1]>=nums2[n2-1]) {return 0;}
        return 1;
    }
    if(n2==0||n1==nums1.size()) {
        if(nums2[n2]>=nums1[n1-1]) {return 0;}
        return -1;
    }
    if(nums1[n1]>=nums2[n2-1]) {
        if(nums2[n2]>=nums1[n1-1]) {return 0;}
        return -1;
    } else {return 1;}
}

int max_of_two(vector<int> &nums1, vector<int> &nums2,int n1,int n2) {
    if(n1==0) {return nums2[n2-1];}
    if(n2==0) {return nums1[n1-1];}
    if(nums1[n1-1]>=nums2[n2-1]) {return nums1[n1-1];}
    return nums2[n2-1];
}

double ave_max_two_of_4(int a,int b,int c,int d) {
    multiset<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    double tmp=*s.rbegin();
    multiset<int>::reverse_iterator it=s.rbegin();
    it++;
    tmp=tmp+*it;
    return tmp/2;
}

double max_two_of_4(vector<int> &nums1, vector<int> &nums2,int n1,int n2) {
    if(n1==0) {return ((double)nums2[n2-1]+(double)nums2[n2-2])/2;}
    if(n2==0) {return ((double)nums1[n1-1]+(double)nums1[n1-2])/2;}
    int b=0;
    int d=0;
    if(n1>1) {b=nums1[n1-2];}
    if(n2>1) {d=nums2[n2-2];}
    return ave_max_two_of_4(nums1[n1-1],b,nums2[n2-1],d);
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int sum=(nums1.size()+nums2.size())/2+1;
    int min=0;
    int max=sum;
    if(nums2.size()<sum) {min=sum-nums2.size();}
    if(nums1.size()<sum) {max=nums1.size();}
    while(min<max) {
        int mid=min+(max-min)/2;
        int ret=check(nums1,nums2,mid,sum-mid);
        if(ret==0) {
            min=mid;
            break;
        }
        if(ret>0) {
            min=mid+1;
            continue;
        }
        max=mid-1;
        continue;
    }
    bool isTwo=true;
    if((nums1.size()+nums2.size())%2==1) {isTwo=false;}
    if(isTwo) {return max_two_of_4(nums1,nums2,min,sum-min);}
    return max_of_two(nums1,nums2,min,sum-min);
}