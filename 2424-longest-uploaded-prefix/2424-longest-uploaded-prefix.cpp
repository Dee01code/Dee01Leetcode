class LUPrefix {
public:
    vector<int> arr;
    int top;
    LUPrefix(int n) {
        arr.resize(n+1,0);
        top=0;
    }
    
    void upload(int video) {
        arr[video] = 1;
        if(top == video-1){
            while((video < arr.size()) && arr[video]==1){
                top = video;
                video++;
            }
        }
    }
    
    int longest() {
        return top;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */