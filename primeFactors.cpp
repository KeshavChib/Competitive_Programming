int N = 1e6 + 1;

vector<int> sieve;

vector<int> primesFactors(int x){
    if(sieve.size() == 0){
        sieve.resize(N);
        for(int i=0;i<N;i++) sieve[i] = i;

        for(int i=2;i*i<N;i++){
            if(sieve[i] != i) continue;
            for(int j=i*i;j<N;j += i){
                sieve[j] = i;
            }
        } 
    }

    vector<int> res;
    while(x != 1){
        int div = sieve[x];
        while(x%div == 0) x = x/div;
        res.push_back(div);
    }
    return res;
}
