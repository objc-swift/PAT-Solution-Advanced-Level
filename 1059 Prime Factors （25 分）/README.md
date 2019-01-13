# PAT-solution
也可以先构造素数表
```
vector<int> prime(100001,1);
for(int i=2;i * i < 100001;i++){
//注意因为求的是素数，所以下标都是从2，这里下标是1会错误
    for(int j=2;j * i < 100001;j++)
        prime[i*j] = 0;
}
```


