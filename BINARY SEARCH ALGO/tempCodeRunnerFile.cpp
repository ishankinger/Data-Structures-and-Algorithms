
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;
    int low=0;
    int high=n-1;
    cout<<binSortRecursive(arr,n,low,high,k)<<"\n";
    return 0;
}