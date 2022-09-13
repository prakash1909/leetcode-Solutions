class Solution {
public:
int findBytes(int num){
if(num & (1<<7)){
if(num & (1<<6)){
if(num & (1<<5)){
if(num & (1<<4)){
if(num & (1<<3)){
return 6;
}
return 4;
}
return 3;
}
return 2;
}
return 5;
}
return 1;
}
int helper(vector<int> data, int i){
int bits = findBytes(data[i]);
if(bits==5 || bits==6){return -1;}

    if(bits==1){return i;}
    if(bits==2){
        if(i+1<data.size() && findBytes(data[i+1])==5){
            return i+1;
        }
    }
    if(bits==3){
        if(i+1<data.size() && findBytes(data[i+1])==5){
            if(i+2<data.size() && findBytes(data[i+2])==5){
                return i+2;
            }
        }
    }
    if(bits==4){
        if(i+1<data.size() && findBytes(data[i+1])==5){
            if(i+2<data.size() && findBytes(data[i+2])==5){
                if(i+3<data.size() && findBytes(data[i+3])==5){
                    return i+3;
                }
            }
        
        }
    }
    return -1;
}

bool validUtf8(vector<int>& data) {
    for(int i=0; i<data.size(); i++){
        i = helper(data, i);
        if(i==-1){
            return false;
        }
    }
    return true;   
}
};