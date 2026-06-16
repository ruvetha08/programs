bool checkGoodInteger(int n) {
    int d,s1=0,s2=0;
    while(n>0){
        d=n%10;
        s1+=d;
        s2+=d*d;
        n/=10;
    }
    int s=s2-s1;
    if(s>=50)
    {
        return true;
    }
    return false;
}
