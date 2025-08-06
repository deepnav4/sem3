pair<int,int> fxn1(int &a,int &b){
    a++;
    b++;
    return {a,b}; 
}

int main1(){
    int a = 10;
    int b = 20;
    pair<int,int>ans = fxn1(a,b);
    cout<<a<<" "<<b;
}