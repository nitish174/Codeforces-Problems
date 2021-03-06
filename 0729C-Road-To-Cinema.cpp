#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,k,s,t;
  scanf("%lld %lld %lld %lld",&n,&k,&s,&t);
  long long nums[k+2];
  long long cars[n][2];
  nums[0] = 0;
  nums[k+1] = s;
  for (int i=0;i<n;i++){
    scanf("%lld %lld",&cars[i][0],&cars[i][1]);
  }
  for (int i=1;i<=k;i++){
    scanf("%lld",&nums[i]);
  }
  sort(nums,nums+k+2);
  long long lo = 0, hi = t*2, pos = 0, res, mid, valid, cur;
  while (lo<hi){
    mid = (lo+hi)/2;
    res = 0;
    valid = 1;
    for (int i=1;i<k+2;i++){
      if (nums[i]-nums[i-1]>mid){
        valid = 0;
        break;
      }
      cur = min(nums[i]-nums[i-1],mid-(nums[i]-nums[i-1]));
      res += cur+(nums[i]-nums[i-1]-cur)*2;
    }
    if (res<=t&&valid){
      hi = mid;
      pos = 1;
    }else lo = mid+1;
  }
  long long ans = 99999999999;
  for (int i=0;i<n;i++){
    if (cars[i][1]>=lo) ans = min(ans,cars[i][0]);
  }
  if (ans==99999999999||!pos) printf("-1\n");
  else printf("%lld\n",ans);
}
