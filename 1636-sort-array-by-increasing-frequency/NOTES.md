*lambda*  loda function dekh lo agar freuenncy ke hisab se sort krne ko aa jaye map mein.
```
sort(nums.begin(), nums.end(), [&](int a, int b){
return mp[a]== mp[b]? a>b: mp[a]< mp[b];
});
```