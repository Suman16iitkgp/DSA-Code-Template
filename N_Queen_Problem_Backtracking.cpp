int n;
int numOfSol = 0;

bool is_valid(int row,int col,vector<int> &Qpos){
    for(int prow=0; prow<row; prow++){
        int pcol = Qpos[prow];
        if(pcol==col || abs(prow-row)==abs(pcol-col)){
            return 0;
        }
    }
    return 1;
}
set<vector<int>> allSols;
void rec(int row, vector<int> &Qpos){
    if(row==n){
        numOfSol++;
        allSols.insert(Qpos);
        return;
    }
    for(int col=0;col<n;col++){
        if(is_valid(row,col,Qpos)){
            Qpos.push_back(col);
            rec(row+1,Qpos);
            Qpos.pop_back();
        }
    }
}

void solve(){
    cin>>n;
    vector<int> arr;
    rec(0,arr);
    cout<<numOfSol<<endl;
}
