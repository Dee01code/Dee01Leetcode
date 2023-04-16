class Solution {
public:
    int addMinimum(string w) {
        
        int n = w.size();
        if(n==1) return 2;
        
        int cnt = 0;
        for(int i = 0; i<n;){
            if(w[i] == 'a'){
                if(i < n-1){ 
                    if(w[i+1] == 'c'){
                        cnt++;
                        i+=2;
                    }
                    else if(w[i+1] == 'a') {cnt += 2; i++;}
                    else i++;
                }
                else{
                    cnt+=2;
                    i++;
                }
            }
            else if(w[i] == 'b'){
                if(i > 0 && i<n-1){
                    if(w[i-1] != 'a' && w[i+1] == 'c'){
                        cnt++;
                        i+=2;
                    }
                    else if(w[i-1] == 'a' && w[i+1] == 'c'){
                        i+=2;
                    }
                    else if(w[i-1] == 'a' && w[i+1] != 'c'){
                        cnt++;
                        i++;
                    }
                    else if(w[i-1] != 'a' && w[i+1] != 'c'){
                        cnt += 2;
                        i++;
                    }
                    else i++;
                }
                else if(i==0 && i<n-1){
                    if(w[i+1] == 'c'){
                        cnt++; 
                        i += 2;
                    }
                    else if(w[i+1] == 'b'){
                        cnt+=2;
                        i++;
                    }
                    else if(w[i+1] == 'a'){
                        i++;
                        cnt+=2; 
                    }
                    else i++;
                }
                else if(i > 0 && i == n-1){
                    if(w[i-1] == 'a'){
                        cnt++;
                    }
                    else if(w[i-1] == 'b'){
                        cnt += 2;
                    }
                    else if(w[i-1] == 'c'){
                        cnt += 2;
                    }
                    i++;
                }
                else i++;
            }
            else{
                if(i == 0){
                    cnt += 2;
                    i++;
                }
                else if(i > 0 && i<n-1){
                    if(w[i-1] == 'c'){
                        cnt += 2;
                        i++;
                    }
                    else i++;
                }
                else if(i == n-1){
                    if(w[i-1] == 'c'){
                        cnt += 2;
                        i++;
                    }
                    else i++;
                }
                else i++;
            }
        }
        return cnt;
        
    }
};