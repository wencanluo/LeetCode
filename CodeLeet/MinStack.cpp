class MinStack {
public:
    stack<int> D;
    stack<int> S;
    
    void push(int x) {
        D.push(x);
        
        if(S.empty()){
            S.push(x);
        }else{
            int t = S.top();
            if(x <= t){
                S.push(x);
            }
        }
    }

    void pop() {
        if(!D.empty()){
            int x = D.top();
            D.pop();
            
            int t = S.top();
            if(x <= t){
                S.pop();
            }
        }
    }

    int top() {
        return D.top();
    }

    int getMin() {
        return S.top();
    }
};