#include<bits/stdc++.h>
using namespace std;

void Selection_Sort(vector<int> &arr,int n){
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
}

void Bubble_sort(vector<int> &arr,int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

void Insertion_sort(vector<int> &arr,int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]) {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++) arr[i]=temp[i-low];
}
void Msort(vector<int> &arr, int low,int high){
    if(low==high) return;
    int mid=(low+high)/2;
    Msort(arr,low,mid);
    Msort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void Merge_Sort(vector<int> &arr,int n){
    Msort(arr,0,n-1);
}

int Partition_index(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1) i++;
        while(arr[j]>=pivot && j>=low+1) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void Quick_sort(vector<int> &arr,int low,int high){
    if(low<high){
        int P_ind= Partition_index(arr,low,high);
        Quick_sort(arr,low,P_ind-1);
        Quick_sort(arr,P_ind+1,high);
    }
}

// *****ARRAYS*********

void Intersect(vector<int> &arr1,int n1,vector<int> &arr2,int n2){
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]) i++;
        else if(arr1[i]>arr2[j]) j++;
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    for(i=0;i<ans.size();i++) cout<< ans[i] <<" ";
}

int longSubarr(vector<int> &arr,int n,int target){
    int sum=arr[0];
    int maxlen=0;
    int left=0;
    int right=0;
    while(right<n){
        while(sum>target && left<=right){
            sum-=arr[left];
            left++;
        }
        if(sum==target) maxlen=max(maxlen,(right-left)+1);
        right++;
        if(right<n) sum+=arr[right];
    }
    return maxlen;
}

void Sort_0s_1s_2s(vector<int> &arr,int n){
    int low=0;
    int high=n-1;
    int mid=0;
   while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++) cout<< arr[i]<<" ";
}

vector<int> Led(vector<int> &arr,int n){
    vector<int> ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi) ans.push_back(arr[i]);
        maxi=max(maxi,arr[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int Longestsq(vector<int> &arr,int n){
    sort(arr.begin(),arr.end());
    int longest=1,cnt=0,lsm=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]-1==lsm){
            cnt++;
            lsm=arr[i];
        }
        else if(arr[i]!=lsm){
            cnt=1;
            lsm=arr[i];
        }
        longest=max(cnt,longest);
    }
    return longest;
}

void rotate_mat(vector<vector<int>> &mat){
    int n=mat.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++) reverse(mat[i].begin(),mat[i].end());
}

vector<int> spiral_mat(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int top=0, btm=n-1;
    int left=0, right=m-1;
    vector<int> ans;
    while(top<=btm && left<=right){
        for(int i=left;i<=right;i++) ans.push_back(mat[top][i]);
        top++;
        for(int i=top;i<=btm;i++) ans.push_back(mat[i][right]);
        right--;
        if(top<=btm){
           for(int i=right;i>=left;i--) ans.push_back(mat[btm][i]);
           btm--;
        }
        if(left<=right){
          for(int i=btm;i>=top;i--) ans.push_back(mat[i][left]);
            left++;
        }
    }
    return ans;
}

vector<int> row(int r){
    int res=1;
    vector<int> ans_row;
    ans_row.push_back(1);
    for(int i = 0; i < r; i++){
        res = res * (r - i);
        res = res / (i+1);
        ans_row.push_back(res);
    }
    return ans_row;
}
vector<vector<int>> PascalTriangle(int n){
    vector<vector<int>> ans;
    for(int i=0;i<n;i++) ans.push_back(row(i));
    return ans;
}

vector<int> Majority(vector<int> &arr){
    int c1=0;
    int c2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(c1==0 && el2!=arr[i]){
            c1=1;
            el1=arr[i];
        }
        else if(c2==0 && el1!=arr[i]){
            c2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1) c1++;
        else if(arr[i]==el2) c2++;
        else{
            c1--;
            c2--;
        }
    }
    vector<int> ans;
    c1=0;
    c2=0;
    for(int i=0;i<arr.size();i++){
        if(el1==arr[i]) c1++;
        if(el2==arr[i]) c2++;
    }
    int mini=(int)(arr.size()/3)+1;
    if(c1>=mini) ans.push_back(el1);
    if(c2>=mini) ans.push_back(el2);
    sort(ans.begin(),ans.end());
    return ans;
}

int SubArrSumK(vector<int> &arr,int k){
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        xr=xr^arr[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

vector<vector<int>> MergeOverlap(vector<vector<int>> &mat){
    int n=mat.size();
    sort(mat.begin(),mat.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || mat[i][0]>ans.back()[1]) ans.push_back(mat[i]);
        else ans.back()[1]=max(ans.back()[1],mat[i][1]);
    }
    return ans;
}

vector<int> MissingAndRepeating(vector<int> arr){
    long long s1=0,s2=0;
    long long n=arr.size();
    long long sn1=(n*(n+1))/2;
    long long sn2=(n*(n+1)*(2*n+1))/6;
    for (int i=0;i<n;i++){
        s1+=arr[i];
        s2+=(long long) arr[i]*(long long) arr[i];
    }
    long long val1=s1-sn1;
    long long val2=s2-sn2;
    val2=val2/val1;
    long long x=(val1+val2)/2;
    long long y=x-val1;
    return {(int)y,(int)x};
}

int MaxProdSub_arr(vector<int> &arr){
    int maxi=INT_MIN;
    int prefix=1;
    int sufix=1;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(prefix==0) prefix=1;
        if(sufix==0) sufix=1;
        prefix=prefix*arr[i];
        sufix=sufix*arr[n-i-1];
        maxi=max(maxi,max(prefix,sufix));
    }
    return maxi;
}

//Binary Search.......

int BinaryIndex(vector<int> &arr,int n,int k){
    int low=0,high=n-1;
    sort(arr.begin(),arr.end());
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k) return mid;
        else if(arr[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int Lowerbound(vector<int> &arr,int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int Upperbound(vector<int> &arr,int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>k){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
vector<int> first_last_appear(vector<int> &arr,int k){
    vector<int> ans;
    int n=arr.size();
    int lb=Lowerbound(arr,k);
    int ub=Upperbound(arr,k);
    if(lb==n||arr[lb]!=k) return {lb,ub-1};
}

int BSinRotated(vector<int> &arr,int k){
    int n=arr.size(),low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k) return mid;
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k<=arr[mid])  high=mid-1;
            else low=mid+1;
        }
        else{
            if(arr[mid]<=k && k<=arr[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

int BSpeak(vector<int> &arr){
    int n=arr.size();
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid-1]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int BSsqrt(int k){
    int low=0,high=k;
    int ans=1;
    while(low<=high){
        int mid=(low+high)/2;
        if((mid*mid)<=k) {
            ans= mid;
            low=mid+1;
        }
        else high=mid-1; 
    }
    return ans;
}

int FindMax(vector<int> &arr){
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++) maxi=max(arr[i],maxi);
    return maxi;
}
int FindMin(vector<int> &arr){
    int n=arr.size();
    int mini=INT_MAX;
    for(int i=n-1;i>=0;i--) mini=min(mini,arr[i]);
    return mini;
}
int CalTolHrs(vector<int> &arr,int hr){
    int THr=0;
    int n=arr.size();
    for(int i=0;i<n;i++) THr+=ceil((int)arr[i]/(int)hr);
    return THr;
}
int MinRateToEat(vector<int> &arr,int hr){
    int low=1,high=FindMax(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int THr=CalTolHrs(arr,mid);
        if(THr<=hr) high=mid-1;
        else low=mid+1;
    }
    return low;
}

bool Possible(vector<int> &arr,int day,int m,int k){
    int n=arr.size();
    int cnt=0,No_Of_Bouquets=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=day) cnt++;
        else{
            No_Of_Bouquets+=(cnt/k);
            cnt=0;
        }
    }
    No_Of_Bouquets+=(cnt/k);
    return No_Of_Bouquets>=m;
}
int RoseGarden(vector<int> &arr,int m,int k){
    long long val=m*1LL*k*1LL;
    if(val>arr.size()) return -1;
    int low=FindMin(arr);
    int high=FindMax(arr);
    while(low<=high){
        int mid=(low+high)/2;
        if(Possible(arr,mid,m,k)){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}

int Day(vector<int> &arr,int cap){
    int days=1,load=0,n=arr.size();
    for(int i=0;i<n;i++){
        if(load+arr[i]>cap){
            days++;
            load=arr[i];
        }
        else load+=arr[i];
    }
    return days;
}
int Sum(vector<int> &arr){
    int sum=0;
    for(int i=0;i<arr.size();i++) sum+=arr[i];
    return sum;
}
int capacity(vector<int> &arr,int days){
    int low=FindMax(arr), high=Sum(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int Days=Day(arr,mid);
        if(Days<=days) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int KthMissNUM(vector<int> &arr,int k){
    int low=0,n=arr.size(),high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k) low=mid+1;
        else high=mid-1;
    }
    return low+k;
}

bool canweplace(vector<int> &arr,int dist,int k){
    int cnt=1,last=arr[0],n=arr.size();
    for(int i=1;i<n;i++){
        if(arr[i]-last>=dist) {
            cnt++;
            last=arr[i];
        }
    }
    if (cnt>=k) return true;
    else return false;
}
int MinDist(vector<int> &arr,int k){
    int low=0,n=arr.size(),high=arr[n-1]-arr[0],ans=0;
    while (low<=high){
        int mid=(low+high)/2;
        if(canweplace(arr,mid,k)==true){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}

//BINARY TREES(BT).
//TreeNode* root=new TreeNode(1);
 //   root->left=new TreeNode(2);
 //   root->right=new TreeNode(3);
  //  root->left->right=new TreeNode(5);
   // vector<vector<int>> Level=LevelOrder(root);
  //  for(auto level : Level){
  //      for(auto val : level){
  //          cout << val << " ";
  //      }
  //      cout << endl;
   // }

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

void PreOrder(TreeNode* root){
    if(root==nullptr) return;
    cout<< root->val<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(TreeNode* root){
    if(root==nullptr) return;
    InOrder(root->left);
    cout<< root->val<<" ";
    InOrder(root->right);
}

void PostOrder(TreeNode* root){
    if(root==nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<< root->val<<" ";
}

vector<vector<int>> LevelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> PreOrderTraversal(TreeNode* root){
    vector<int> preOrder;
    if(root==nullptr) return preOrder;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preOrder.push_back(root->val);
        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) st.push(root->left);
    }
    return preOrder;
}

vector<int> InOrderTraversal(TreeNode* root){
    vector<int> inOrder;
    stack<TreeNode*> st;
    TreeNode* node=root;
    while(true){
       if(node!=NULL){
        st.push(node);
        node=node->left;
       }
       else{
        if(st.empty()==true) break;
        node=st.top();
        st.pop();
        inOrder.push_back(node->val);
        node=node->right;
       }
    }
    return inOrder;
}

vector<int> PostOrderTraversal(TreeNode* root){
    vector<int> postOrder;
    if(root==NULL) return postOrder;
    stack<TreeNode*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL) st1.push(root->left);
        if(root->right!=NULL) st1.push(root->right);
    }
    while(!st2.empty()){
        postOrder.push_back(st2.top()->val);
        st2.pop();
    }
    return postOrder;
}

vector<vector<int>> PreInPostTraversal(TreeNode* root){
    vector<int> pre, in, post;
    if(root == NULL) return {pre, in, post};
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left != NULL) st.push({it.first->left, 1});
        }
        else if(it.second == 2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right != NULL)  st.push({it.first->right, 1});
        }
        else{
            post.push_back(it.first->val);
        }
    }
    return {pre, in, post};
}

int MaxDepthBT(TreeNode* root){
    if(root==NULL) return 0;
    int lh=MaxDepthBT(root->left);
    int rh=MaxDepthBT(root->right);
    return 1+max(lh,rh);
}

int HeightOfBT(TreeNode* root,int &Dia){
     if(root==NULL) return 0;
     int lh=HeightOfBT(root->left,Dia);
     int rh=HeightOfBT(root->right,Dia);
     Dia=max(Dia,lh+rh);
     return 1+max(lh,rh);
}
int DiaOfBT(TreeNode* root){
    int Dia=0;
    HeightOfBT(root,Dia);
    return Dia;
}

int Maxpath(TreeNode* node,int &maxi){
    if(node==NULL) return 0;
    int ls=max(0,Maxpath(node->left,maxi));
    int rs=max(0,Maxpath(node->right,maxi));
    maxi=max(maxi,ls+rs+node->val);
    return node->val+max(ls,rs);
}
int MaxSumPathBT(TreeNode* root,){
    int maxi=INT_MIN;
    Maxpath(root,maxi);
    return maxi;
}

vector<vector<int>> ZigZagBT(TreeNode* root){
    vector<vector<int>> result;
    if(root==NULL) return result;
    queue<TreeNode*> q;
    q.push(root);
    bool left_right=true;
    while(!q.empty());{
        int n=q.size();
        vector<int> row(n);
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            int ind=(left_right)? i:(n-1-i);
            row[ind]=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        left_right!=left_right;
        result.push_back(row);
    }
    return result;
}

bool isleaf(TreeNode* node){
    return (node->left == NULL && node->right == NULL);
}
void addLeftBoundary(TreeNode* root,vector<int> &result){
    TreeNode* cur=root->left;
    while(cur){
        if(!isleaf(cur)) result.push_back(cur->val);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
}
void addRightBoundary(TreeNode* root,vector<int> &result){
    TreeNode* cur=root->right;
    vector<int> temp;
    while(cur){
        if(!isleaf(cur)) temp.push_back(cur->val);
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }
    for(int i=temp.size()-1;i>=0;--i) result.push_back(temp[i]);
}
void addLeaf(TreeNode* root,vector<int> &result){
    if(isleaf(root)){
         result.push_back(root->val);
         return;
    }
    if(root->left) addLeaf(root->left,result);
    if(root->right) addLeaf(root->right,result);
}
vector<int> BoundaryBT(TreeNode* root){
    vector<int> result;
    if(root==NULL) return result;
    if(!isleaf(root)) result.push_back(root->val);
    addLeftBoundary(root,result);
    addLeaf(root,result);
    addRightBoundary(root,result);
    return result;
}

vector<vector<int>> VerticalTraversalBT(TreeNode* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        TreeNode* node=p.first;
        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left) todo.push({node->left,{x-1,y+1}});
        if(node->right) todo.push({node->right,{x+1,y+1}});
    }
    vector<vector<int>> ans;
    for(auto p:nodes){
        vector<int> col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

vector<int> TopViewBT(TreeNode* root){
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it:q.front();
        q.pop();
        TreeNode* node=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end()) mpp[line]=node->val;
        if(node->left!=NULL) q.push({node->left,line-1});
        if(node->right!=NULL) q.push({node->right,line+1});
    }
    for(auto it:mpp) ans.push_back(it.second);
    return ans;
}

vector<int> BottomViewBT(TreeNode* root){
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode* node=it.first;
        int line=it.second;
        mpp[line]=node->val;
        if(node->left!=NULL) q.push({node->left,line-1});
        if(node->right!=NULL) q.push({node->right,line+1});
    }
    for(auto it:mpp) ans.push_back(it.second);
    return ans;
}

void recursion(TreeNode* root, int level, vector<int> &res){
    if(root==NULL) return;
    if(res.size()==level) res.push_back(root->val);
    recursion(root->right,level+1,res);
    recursion(root->left,level+1,res);
}
vector<int> RightsideViewBT(TreeNode* root){
    vector<int> res;
    recursion(root,0,res);
    return res;
}

bool isSymmetricHelp(TreeNode* left, TreeNode* right){
    if(left==NULL || right==NULL) return left==right;
    if(left->val!=right->val) return false;
    return isSymmetricHelp(left->left,right->right) && isSymmetricHelp(left->right,right->left);
}
bool isSymmetrical(TreeNode* root){
    return root==NULL || isSymmetricHelp(root->left,root->right);
}

bool getpath(TreeNode* root, vector<int> &arr, int x){
    if(!root) return false;
    arr.push_back(root->val);
    if(root->val==x) return true;
    if(getpath(root->left,arr,x)||getpath(root->right,arr,x)) return true;
    arr.pop_back();
    return false;
}
vector<int> Root_Node(TreeNode* A,int B){
    vector<int> arr;
    if(A==NULL) return arr;
    getpath(A,arr,B);
    return arr;
}

TreeNode* LowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL||root==p||root==q) return root;
    TreeNode* left=LowestCommonAncestor(root->left,p,q);
    TreeNode* right=LowestCommonAncestor(root->right,p,q);
    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root;
}

int WidthOfBT(TreeNode* root){
    if(!root) return 0;
    int ans=0;
    queue<pair<TreeNode*,long long>> q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        long long mmin=q.front().second;
        long long first,last;
        for(int i=0;i<size;i++){
            long long cur_id=q.front().second-mmin;
            TreeNode* node=q.front().first;
            q.pop();
            if(i=0) first=cur_id;
            if(i==size-1) last=cur_id;
            if(node->left) q.push({node->left,cur_id*2+1});
            if(node->right) q.push({node->right,cur_id*2+2});
        }
        ans=max(ans,(int)last-first+1);
    }
    return ans;
}

void ChangeBT(BinaryTreeNode<int> *root){
    if(root==NULL) return;
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    if(child>=root->data) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    ChangeBT(root->left);
    ChangeBT(root->right);
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data=tot;
}

void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* current=q.front();
        q.pop();
        if(current->left){
            parent_track[current->left]=current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right]=current;
            q.push(current->right);
        }
    }
}
vector<int> DistanceKinBT(TreeNode* root,TreeNode* target,int k){
    unordered_map<TreeNode*,TreeNode*> parent_track;
    markparents(root,parent_track);
    unordered_map<TreeNode*,bool> visit;
    queue<TreeNode*> Q;
    Q.push(target);
    visit[target]=true;
    int cur_level=0;
    while(!Q.empty()){
        int size=Q.size();
        if(cur_level++==k) break;
        for(int i=0;i<size;i++){
            TreeNode* current=Q.front();
            Q.pop();
            if(current->left&&!visit[current->left]){
                Q.push(current->left);
                visit[current->left]=true;
            }
            if(current->right&&!visit[current->right]){
                Q.push(current->right);
                visit[current->right]=true;
            }
            if(parent_track.find(current)!=parent_track.end()&&!visit[parent_track[current]]){
                Q.push(parent_track[current]);
                visit[parent_track[current]]=true;
            }
        }
    }
    vector<int> res;
    while(!Q.empty()){
        TreeNode* current=Q.front();
        Q.pop();
        res.push_back(current->val);
    }
    return res;
}

int findMaxDist(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mpp,BinaryTreeNode<int>* target){
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    map<BinaryTreeNode<int>*,int> visit;
    visit[target]=1;
    int maxi=0;
    while(!q.empty()){
        int sz=q.size();
        int fl=0;
        for(int i=0;i<sz;i++){
            auto node=q.front();
            q.pop();
            if(node->left&&!visit[node->left]){
                fl=1;
                visit[node->left]=1;
                q.push(node->left);
            }
             if(node->right&&!visit[node->right]){
                fl=1;
                visit[node->right]=1;
                q.push(node->right);
            }
            if(mpp.find(node)!=mpp.end()&&!visit[mpp[node]]){
                fl=1;
                visit[mpp[node]]=1;
                q.push(mpp[node]);
            }
        }
        if(fl) maxi++;
    }
    return maxi;
}
BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mpp,int start){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* res=NULL;
    while(!q.empty()){
        BinaryTreeNode<int>* node=q.front();
        if(node->data==start) res=node;
        q.pop();
        if(node->left){
            mpp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            mpp[node->right]=node;
            q.push(node->right);
        }
    }
    return res;
}
int TimeToBurnTree(BinaryTreeNode<int>* root,int start){
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mpp;
    BinaryTreeNode<int>* target=bfsToMapParents(root,mpp,start);
    int maxi=findMaxDist(mpp,target);
    return maxi;
}

int findHeightLeft(TreeNode* node){
    int cnt=0;
    while(node){
        cnt++;
        node=node->left;
    }
    return cnt;
}
int findHeightRight(TreeNode* node){
    int cnt=0;
    while(node){
        cnt++;
        node=node->right;
    }
    return cnt;
}
int CountNodesofBT(TreeNode* root){
    if(root==NULL) return 0;
    int lh=findHeightLeft(root);
    int rh=findHeightRight(root);
    if(lh==rh) return (1<<lh)-1;
    return 1+CountNodesofBT(root->left)+CountNodesofBT(root->right);
}

TreeNode* buildTreeinpre(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int>&mpp){
    if(preStart>preEnd||inStart>inEnd) return NULL;
    TreeNode* root=new TreeNode(preorder[preStart]);
    int inRoot=mpp[root->val];
    int numsLeft=inRoot-inStart;
    root->left=buildTreeinpre(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mpp);
    root->right=buildTreeinpre(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mpp);
    return root;
}
TreeNode* BuildTreeInPre(vector<int> &preorder,vector<int> &inorder){
    if(inorder.size()!=preorder.size()) return NULL;
    map<int,int> mpp;
    for(int i=0;i<inorder.size();i++) mpp[inorder[i]]=i;
    TreeNode* root=buildTreeinpre(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}

TreeNode* buildTreeinpost(vector<int> &inorder,int inS,int inE,vector<int> &postorder,int postS,int postE,map<int,int> &hm){
    if(inS>inE||postS>postE) return NULL;
    TreeNode* root=new TreeNode(postorder[postE]);
    int inRoot= hm[postorder[postE]];
    int numsLeft=inRoot-inS;
    root->left=buildTreeinpost(inorder,inS,inRoot-1,postorder,postS,postS+numsLeft-1,hm);
    root->right=buildTreeinpost(inorder,inRoot+1,inE,postorder,postS+numsLeft,postE-1,hm);
    return root;
}
TreeNode* BuildTreeInPost(vector<int> &inorder,vector<int> &postorder){
    if(inorder.size()!=postorder.size()) return NULL;
    map<int,int> hm;
    for(int i=0;i<inorder.size();++i) hm[inorder[i]]=i;
    return buildTreeinpost(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hm);
}

string Serialize(TreeNode* root){
    if(root==NULL) return "";
    string s="";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curNode=q.front();
        q.pop();
        if(curNode==NULL) s.append("#,");
        else s.append(to_string(curNode->val)+',');
        if(curNode!=NULL){
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return s;
}
TreeNode* Deserialize(string data){
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    if(str == "#") return NULL;
    TreeNode* root=new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#") node->left=NULL;
        else{
            TreeNode* leftNode=new TreeNode(stoi(str));
            node->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#") node->right=NULL;
        else{
            TreeNode* rightNode=new TreeNode(stoi(str));
            node->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//Moris Traversal
vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            inorder.push_back(cur->val);
            cur=cur->right;
        }
        else{
            TreeNode* prev=cur->left;
            while(prev->right&&prev->right!=cur) prev=prev->right;
            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }
            else {
                prev->right=NULL;
                inorder.push_back(cur->val);
                cur=cur->right;
            }
        }
    }
    return inorder;
}

//BINARY SEARCH TREE
TreeNode* searchBST(TreeNode* root, int val){
    while(root!=NULL&&root->val!=val){
        root=val<root->val? root->left:root->right;
    }
    return root;
}

int findCeilinBST(BinaryTreeNode<int>* root,int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }
        if(key>root->data) root=root->right;
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}

int FloorInBST(TreeNode<int>* root, int key){
    int floor=-1;
    while(root){
        if(root->val==key){
            floor=root->val;
            return floor;
        }
        if(key>root->val){
            floor=root->val;
            root=root->right;
        }
        else root=root->left;
    }
    return floor;
}

TreeNode* InsertIntoBST(TreeNode* root, int val){
    if(root==NULL) return new TreeNode(val);
    TreeNode* cur=root;
    while(cur){
        if(cur->val<=val){
            if(cur->right!=NULL) cur=cur->right;
            else{
                cur->right=new TreeNode(val);
                break;
            }
        }
        else{
            if(cur->left!=NULL) cur=cur->left;
            else{
                cur->left=new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

TreeNode* findlastRight(TreeNode* root){
    if(root->right==NULL)return root;
    return findlastRight(root->right);
}
TreeNode* helper(TreeNode* root){
    if(root->left==NULL) return root->right;
    else if(root->right==NULL) return root->left;
    TreeNode* rightChild=root->right;
    TreeNode* lastRight= findlastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}
TreeNode* DeleteNodeBST(TreeNode* root,int key){
    if(root==NULL) return NULL;
    if(root->val==key) return helper(root);
    TreeNode* dummy=root;
    while(root!=NULL){
        if(root->val>key){
            if(root->left!=NULL&& root->left->val==key){
                root->left=helper(root->left);
                break;
            }
            else root=root->left;
        }
        else {
            if(root->right!=NULL&& root->right->val==key) {
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
        }
    }
    return dummy;
}

bool isBST(TreeNode* root, long long minval,long long maxval){
    if(root==NULL) return true;
    if(root->val>=maxval||root->val<=minval) return false;
    return isBST(root->left,minval,root->val)&&isBST(root->right,root->val,maxval);
}
bool isBST(TreeNode* root){
    return isBST(root,LLONG_MIN,LLONG_MAX);
}

TreeNode* LCA_BST(TreeNode* root,TreeNode* p,Treenode* q){
    if(root==NULL) return NULL;
    int curr=root->val;
    if(curr<p->val&&curr<q->val) return LCA_BST(root->right,p,q);
    if(curr>p->val&&curr>q->val) return LCA_BST(root->left,p,q);
    return root;
}

//GRAPHS----------------------------------
//Matrix form and List form
//  ***Matrix****
// int n,m;
// cin>> n>>m;
// int adj[n+1][m+1];
// for(int i=0;i<m;i++){
//   int u,v;
//  cin>> u>>v;
//   adj[u][v]=1;
//   adj[v][u]=1;
// }

//    ***List***
// int n,m;
// cin>>n>>m;
// vector<int> adj[n+1];
// for(int i=0;i<m;i++){
//   int u,v;
//   cin>>u>>v;
//   adj[u].push_back(v);
//   adj[v].push_back(u);
//  }

vector<int> BFSgraph(int v,vector<int> adj[]){
    vector<int> bfs;
    int vis[v]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,adj,vis,ls);
    }
}
vector<int> DFSgraph(int v,vector<int> adj[]){
    int vis[v]={0};
    int start =0;
    vector<int> ls;
    dfs(start,adj,vis,ls);
    return ls;
}

void dfs_province(int node,vector<int> adjLs[],int vis[]){
    vis[node]=1;
    for(auto it:adjLs[node]){
        if(!vis[it]) dfs_province(it,adjLs,vis);
    }
}
int NumProvinces(vector<vector<int>> adj,int v){
    vector<int> adjLs[v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j]==1&&i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int vis[v]={0};
    int cnt=0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            cnt++;
            dfs_province(i,adjLs,vis);
        }
    }
    return cnt;
}

void bfs_connectedComponents(int row,int col,vector<vector<int>> &vis, vector<vector<char>> &grid){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow=row+delrow;
                int ncol=col+delcol;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]=='1'&&!vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int Connected_comp(vector<vector<char>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col]&&grid[row][col]=='1'){
                cnt++;
                bfs_connectedComponents(row,col,vis,grid);
            }
        }
    }
    return cnt;
}

void dfs_floodfill(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newcolor,int delRow[],int delCol[],int inicolor){
    ans[row][col]=newcolor;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==inicolor&&ans[nrow][ncol]!=newcolor){
            dfs_floodfill(nrow,ncol,ans,image,newcolor,delRow,delCol,inicolor);
        }
    }
}
vector<vector<int>> FloodFill(vector<vector<int>> &image,int sr,int sc,int newcolor){
    int inicolor=image[sr][sc];
    vector<vector<int>> ans=image;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    dfs_floodfill(sr,sc,ans,image,newcolor,delRow,delCol,inicolor);
    return ans;
}

int RottenOranges(vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
            else vis[i][j]=0;
        }
    }
    int tm=0;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm,t);
        q.pop();
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]==1){
                q.push({{nr,nc},t+1});
                vis[nr][nc]=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=2&&grid[i][j]==1) return -1;
        }
    }
    return tm;
}

bool detectCycle(int src,vector<int>adj[],int vis[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                vis[neigh]=1;
                q.push({neigh,node});
            }
            else if(parent!=neigh){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int v,vector<int> adj[]){
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(detectCycle(i,adj,vis)) return true;
        }
    }
    return false;
}
//in dfs
bool dfsdetectCycle(int node,int parent,vector<int> vis[],vector<int> adj[]){
    vis[node]=1;
    for(auto neigh: adj[node]){
        if(vis[neigh]==0){
            if(dfsdetectCycle(neigh,node,vis,adj)) return true;
        }
        else if(neigh!=parent) return true;
    }
    return false;
}
bool iscycle(int v,vector<int> adj[]){
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfsdetectCycle(i,-1,vis,adj)==true) return true;
        }
    }
    return false;
}

bool dfsCheck(int node,vector<int> adj[],int vis[],int pathvis[],int check[]){
    vis[node]=1;
    pathvis[node]=1;
    check[node]=0;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathvis,check)){
            pathvis[node]=0;
            return true;
            }
        }
        else if(pathvis[it]){
            pathvis[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathvis[node]=0;
    return false;
}
vector<int> EventualSafenodes(int v,vector<int> adj[]){
    int vis[v]={0};
    int pathvis[v]={0};
    int check[v]={0};
    vector<int> Safenodes;
    for(int i=0;i<v;i++){
        if(!vis[i]) dfsCheck(i,adj,vis,pathvis,check);
    }
    for(int i=0;i<v;i++){
        if(check[i]==1) Safenodes.push_back(i);
    }
    return Safenodes;
}

void Topodfs(int node,vector<int> &vis,stack<int> &st,vector<int> adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]) Topodfs(it,vis,st,adj);
    }
    st.push(node);
}
vector<int> TopologySort(int v,vector<int> adj[]){
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!vis[i]) Topodfs(i,vis,st,adj);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> TopoSort(int v,vector<int> adj[]){
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]) indegree[it]++;
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return topo;
}

string findOrder(string dict[],int N,int K){
    vector<int> adj[K];
    for(int i=0;i<N-1;i++){
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        for(int ptr=0;ptr<len;ptr++){
            if(s1[ptr]!=s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }
    vector<int> topo=TopoSort(K,adj);
    string ans="";
    for(auto it:topo){
        ans+=char(it+'a');
    }
    return ans;
}

void topoforShortpath(int node,vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        int v=it.first;
        if(!vis[v]) topoforShortpath(v,adj,vis,st);
    }
    st.push(node);
}
vector<int> shortestPathDAG(int N,int M,vector<int> edges[]){
    vector<pair<int,int>> adj[N];
    for(int i=0;i<M;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    vector<int> vis(N,0);
    stack<int> st;
    for(int i=0;i<N;i++){
        if(!vis[i]) topoforShortpath(i,adj,vis,st);
    }
    vector<int> dist(N);
    for(int i=0;i<N;i++) dist[i]=INT_MAX;
    dist[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist[node]+wt<dist[v]) dist[v]=dist[node]+wt;
        }
    }
    return dist;
}

vector<int> ShortPathUDG(int N,int M,vector<vector<int>> edges,int src){
    vector<int> adj[N];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int dist[N];
    for(int i=0;i<N;i++){
        dist[i]=1e9;
    }
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    vector<int> ans(N,-1);
    for(int i=0;i<N;i++){
        if(dist[i]!=1e9) ans[i]=dist[i];
    }
    return ans;
}

int WordLadderLength(string StartWord,string TargetWord,vector<string> &WordList){
    queue<pair<string,int>> q;
    q.push({StartWord,1});
    unordered_set<string> st(WordList.begin(),WordList.end());
    st.erase(StartWord);
    while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==TargetWord) return steps;
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                if(ch==original) continue;
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
    }
    return 0;
}

vector<vector<string>> findSequence(string beginWord,string endWord,vector<string>& WordList){
    unordered_set<string> st(WordList.begin(),WordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level=0;
    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> vec=q.front();
        q.pop();
        if(vec.size()>level){
            level++;
            for(auto it:usedOnLevel) st.erase(it);
            usedOnLevel.clear();
        }
        string word=vec.back();
        if(word==endWord){
            if(ans.size()==0) ans.push_back(vec);
            else if(ans[0].size()==vec.size()) ans.push_back(vec);
        }
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                if(c==original) continue;
                word[i]=c;
                if(st.count(word)>0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;
}

vector<int> DijkstraAlgo_pQ(int v,int s,vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(v,1e9);
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if (dis > dist[node]) continue;
        for(auto it:adj[node]){
            int edgeweight=it[1];
            int adjNode=it[0];
            if(dis+edgeweight<dist[adjNode]){
                dist[adjNode]=dis+edgeweight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

vector<int> dijkstraAlgo_st(int v,int s,vector<vector<int>> adj[]){
    set<pair<int,int>> st;
    vector<int> dist(v,1e9);
    dist[s]=0;
    st.insert({0,s});
    while(!st.empty()){
        auto it=*(st.begin());
        int node=it.second;
        int dis=it.first;
        st.erase(it);
        if (dis > dist[node]) continue;
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];
            if(dis + edgeWeight < dist[adjNode]) {
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
     return dist;
}

vector<int> shorTpathDijkstra(int n,int m,vector<vector<int>>& edges){
    vector<pair<int,int>> adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e9),parent(n+1);
    for(int i=0;i<=n;i++) parent[i]=i;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto it=pq.top();
        int dis=it.first;
        int node=it.second;
        pq.pop();
        if (dis > dist[node]) continue;
        for(auto it:adj[node]){
            int edgew=it.second;
            int adjnode=it.first;
            if(dis+edgew<dist[adjnode]){
                dist[adjnode]=dis+edgew;
                pq.push({dist[adjnode],adjnode});
                parent[adjnode]=node;
            }
        }
    }
    if(dist[n]==1e9) return -1;
    vector<int> path;
    int node=n;
    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;
}

int shortDist(vector<vector<int>>& grid,pair<int,int> src,pair<int,int> destin){
    if(src==destin) return 0;
    queue<pair<int,pair<int,int>>> q;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[src.first][src.second]=0;
    q.push({0,{src.first,src.second}});
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!q.empty()){
        auto it=q.front();
        int dis=it.first;
        int r=it.second.first;
        int c=it.second.second;
        q.pop();
        for(int i=0;i<4;i++){
            int newr=r+dr[i];
            int newc=c+dc[i];
            if(newr>=0&&newr<n&&newc>=0&&newc<m&&grid[newr][newc]==1&&dis+1<dist[newr][newc]){
                dist[newr][newc]=dis+1;
                if(newr==destin.first&&newc==destin.second) return dis+1;
                q.push({dist[newr][newc],{newr,newc}});
            }
        }
    }
    return -1;
}

int MinEffort(vector<vector<int>>& heights){
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>> pq;
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[0][0]=0;
    pq.push({0,{0,0}});
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int diff=it.first;
        int r=it.second.first;
        int c=it.second.second;
        if (diff > dist[r][c]) continue;
        if(r==n-1&&c==m-1) return diff;
        for(int i=0;i<4;i++){
            int newr=r+dr[i];
            int newc=c+dc[i];
            if(newr>=0&&newr<n&&newc>=0&&newc<m){
                int newEff=max(abs(heights[r][c]-heights[newr][newc]),diff);
                if(newEff<dist[newr][newc]){
                    dist[newr][newc]=newEff;
                    pq.push({newEff,{newr,newc}});
                }
            }
        }
    }
    return 0;
}

int CheapestFlight(int n,vector<vector<int>>& flights,int src,int dst,int k){
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:flights) adj[it[0]].push_back({it[1],it[2]});
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    vector<int> dist(n,1e9);
    dist[src]=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int node=it.second.first;
        int cost=it.second.second;
        if(stops>k) continue;
        for(auto iter:adj[node]){
            int adjNode=iter.first;
            int edw=iter.second;
            if(cost+edw<dist[adjNode]&&stops<=k){
                dist[adjNode]=cost+edw;
                q.push({stops+1,{adjNode,cost+edw}});
            }
        }
    }
    if(dist[dst]==1e9) return -1;
    return dist[dst];
}

int minMultion(vector<int>& arr,int start,int end){
    if (start == end) return 0;
    queue<pair<int,int>> q;
    q.push({start,0});
    vector<int> dist(10000,1e9);
    dist[start]=0;
    int mod=10000;
    while(!q.empty()){
        int node=q.front().first;
        int steps=q.front().second;
        q.pop();
        for(auto it:arr){
            int num=(it*node)%mod;
            if(steps+1<dist[num]){
                dist[num]=steps+1;
                if(num==end) return steps+1;
                q.push({num,steps+1});
            } 
        }
    }
    return -1;
}

int countPaths(int n,vector<vector<int>>& roads){
    vector<pair<int,int>> adj[n];
    for(auto it: roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int> dist(n,1e9),ways(n,0);
    dist[0]=0;
    ways[0]=1;
    int mod=(int)(1e9+7);
    while(!pq.empty()){
        long long dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if (dis > dist[node]) continue;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int edw=it.second;
            if(dis+edw<dist[adjNode]){
                dist[adjNode]=dis+edw;
                pq.push({dis+edw,adjNode});
                ways[adjNode]=ways[node];
            }
            else if(dis+edw==dist[adjNode]){
                ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
}

vector<int> Bellman_ford(int v,int s,vector<vector<int>>& edges){
    vector<int> dist(v,1e8);
    dist[s]=0;
    for(int i=0;i<v-1;i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8&& dist[u]+wt<dist[v]) dist[u]=dist[v]+wt;
        }
    }
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v]) return {-1};
    }
    return dist;
}

void short_dist_Floyd_warshall(vector<vector<int>>& mat){
    int n=mat.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1) mat[i][j]=1e9;
            if(i==j) mat[i][j]=0;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1e9) mat[i][j]=-1;
        }
    }
}

int find_city(int n,int m,vector<vector<int>>& edges,int distThreshold){
    vector<vector<int>> dist(n,INT_MAX);
    for(auto it:edges){
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[0]]=it[2];
    }
    for(int i=0;i<n;i++) dist[i][i]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]==INT_MAX||dist[k][j]==INT_MAX) continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int cntCity=n;
    int cityNo=-1;
    for(int city=0;city<n;city++){
        int cnt=0;
        for(int adjCity=0;adjCity<n;adjCity++){
            if(dist[city][adjCity]<=distThreshold) cnt++;
        }
        if(cnt<=cntCity){
            cntCity=cnt;
            cityNo=city;
        }
    }
    return cityNo;
}

int Prim_spanningTree(int v,vector<vector<int>>& adj[]){
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(v,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;
        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;
        for(auto &it:adj[node]){
            int adjNode=it[0];
            int edw=it[1];
            if(!vis[adjNode]){
                pq.push({edw,adjNode});
            }
        }
    }
    return sum;
}

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)  parent[i] = i;
    }
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path Compression
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int Krushal_spanningTree(int v,vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            int adjNode=it[0];
            int wt=it[1];
            int node=i;
            if (i < adjNode){
                edges.push_back({wt,{node,adjNode}});
            }
        }
    }
    DisjointSet ds(v);
    sort(edges.begin(),edges.end());
    int mstwt=0;
    for(auto &it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUPar(u)!=ds.findUPar(v)){
            mstwt+=wt;
            ds.unionBySize(u,v);
        }
    }
    return mstwt;
}

int numProvinces_dis(int v,vector<vector<int>> adj){
    DisjointSet ds(v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j]==1&&i!=j) ds.unionBySize(i,j);
        }
    }
    int cnt=0;
    for(int i=0;i<v;i++){
        if(ds.findUPar(i)==i) cnt++;
    }
    return cnt;
}

vector<vector<string>> mergeDetails(vector<vector<string>> &details){
    int n=details.size();
    DisjointSet ds(n);
    unordered_map<string,int> mapMailNode;
    for(int i=0;i<n;i++){
        for(int j=1;j<details[i].size();j++){
            string mail=details[i][j];
            if(mapMailNode.find(mail)==mapMailNode.end()) mapMailNode[mail]=i;
            else ds.unionBySize(i,mapMailNode[mail]);
        }
    }
    vector<string> mergedMail[n];
    for(auto it: mapMailNode){
        string mail=it.first;
        int node=ds.findUPar(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i=0;i<n;i++){
        if(mergedMail[i].size()==0) continue;
        sort(mergedMail[i].begin(),mergedMail[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for(auto it:mergedMail[i]) temp.push_back(it);
        ans.push_back(temp);
    }
    return ans;
}

bool isValidIsland(int adjr,int adjc,int n,int m){
    return adjr>=0&&adjr<n&&adjc>=0&&adjc<m;
}
vector<int> numOfIslandDSU(int n,int m,vector<vector<int>>& operators){
    DisjointSet ds(n*m);
    vector<vector<int>> vis(n,vector<int>(m,0));
    memset(vis,0,sizeof vis);
    vector<int> ans;
    int cnt=0;
    for(auto it : operators){
        int r=it[0];
        int c=it[1];
        if(vis[r][c]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[r][c]=1;
        cnt++;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int adjr=r+dr[i];
            int adjc=c+dc[i];
            if(isValidIsland(adjr,adjc,n,m)){
                if(vis[adjr][adjc]==1){
                    int nodeNo=r*m+c;
                    int adjNodeNo=adjr*m+adjc;
                    if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int removeStones(vector<vector<int>>& stones) {
    int maxRow = 0, maxCol = 0;
    for (auto &it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes;
    for (auto &it : stones) {
        int rowNode = it[0];
        int colNode = it[1] + maxRow + 1;
        ds.unionBySize(rowNode, colNode);
        stoneNodes[rowNode] = 1;
        stoneNodes[colNode] = 1;
    }
    int cnt = 0;
    for (auto &it : stoneNodes) {
        if (ds.findUPar(it.first) == it.first) cnt++;
    }
    return stones.size()-cnt;
}

void dfs4(int node,vector<int>& vis,vector<int> adj[],stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]) dfs4(it,vis,adj,st);
    }
    st.push(node);
}
void dfs3(int node,vector<int>& vis,vector<int> adjT[]){
    vis[node]=1;
    for(auto it:adjT[node]){
        if(!vis[it]) dfs3(it,vis,adjT);
    }
}
int kosaRaju_algo(int v,vector<int> adj[]){
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!vis[i]) dfs4(i,vis,adj,st);
    }
    vector<int> adjT[v];
    for(int i=0;i<v;i++){
        vis[i]=0;
        for(auto it:adj[i]) adjT[it].push_back(i);
    }
    int scc=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs3(node,vis,adjT);
        }
    }
    return scc;
}

int timer=1;
void dfs_bridge(int node,int parent,vector<int>& vis,int tin[],int low[],
    vector<int> adj[],vector<vector<int>>& bridges){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs_bridge(it,node,vis,tin,low,adj,bridges);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                bridges.push_back({it,node});
            }
        }
        else low[node]=min(low[node],tin[it]);
    }
}
vector<vector<int>> criticalconnections(int n,vector<vector<int>> &connections){
    vector<int> adj[n];
    for(auto it:connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n,0);
    int tin[n];
    int low[n];
    vector<vector<int>> bridges;
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs_bridge(i,-1,vis,tin,low,adj,bridges);
    }
    return bridges;
}

int timer=0;
void dfs_articulate(int node,int parent,vector<int>& vis,
    int tin[],int low[],vector<int>& mark,vector<int> adj[]){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    int child=0;
    for(auto it: adj[node]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs_articulate(it,node,vis,tin,low,mark,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>=tin[node]&&parent!=-1) mark[node]=1;
            child++;
        }
        else low[node]=min(low[node],tin[it]);
    }
    if(child>1&&parent==-1) mark[node]=1;
}
vector<int> articulationPoints(int v,vector<int> adj[]){
    vector<int> vis(v,0);
    int tin[v];
    int low[v];
    vector<int> mark(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]) dfs_articulate(i,-1,vis,tin,low,mark,adj);
    }
    vector<int> ans;
    for(int i=0;i<v;i++) {
        if(mark[i]==1) ans.push_back(i);
    }
    if(ans.empty()) return {-1};
    return ans;
}

int func(int ind,vector<int>& heights,vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left=func(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1){
        right=func(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind]=min(left,right);
}
int Frog_jump(int n,vector<int> heights){
    if(n==0) return 0;
    vector<int> dp(n,-1);
    return func(n-1,heights,dp);
}

int maxNonAdjSum(vector<int> &nums){
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=prev2;
        int notTake=0+prev;
        int curi=max(take,notTake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}

int ninjaTraining(int n,vector<vector<int>>& points){
    vector<int> prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][1],points[0][0]);
    prev[3]=max(points[0][1],max(points[0][2],points[0][0]));
    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    temp[last]=max(temp[last],points[day][task]+prev[task]);
                }
            }
        }
        prev=temp;
    }
    return prev[3];
}

int mod=1000000007;
int mazeObstacle(int n,int m,vector<vector<int>>& mat){
    vector<int> prev(m,0);
    for(int i=0;i<n;i++){
        vector<int> cur(m,0);
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) cur[j]=0;
            else if(i==0&&j==0) cur[j]=1;
            else{
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=cur[j-1];
                cur[j]=(up+left)%mod;
            }
        }
        prev=cur;
    }
    return prev[m-1];
}


int minSumPathGrid(vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0) dp[i][j]=grid[i][j];
            else{
                int up=grid[i][j];
                if(i>1) up+=dp[i-1][j];
                else up+=1e9;
                int left=grid[i][j];
                if(j>1) left+=dp[i][j-1];
                else left+=1e9;
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}

int minSumPathTriangle(vector<vector<int>>& triangle,int n){
    vector<int> front(n,0),cur(n,0);
    for(int j=0;j<n;j++) front[j]=triangle[n-1][j];
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=triangle[i][j]+front[j];
            int dg=triangle[i][j]+front[j+1];
            cur[j]=min(d,dg);
        }
        front=cur;
    }
    return front[0];
}

int MaxSumPathVar(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<int> prev(m,0),cur(m,0);
    for(int j=0;j<m;j++) prev[j]=mat[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u=mat[i][j]+prev[j];
            int ld=mat[i][j];
            if(j-1>=0) ld+=prev[j-1];
            else ld+=-1e8;
            int rd=mat[i][j];
            if(j+1<m) rd+=prev[j+1];
            else rd+=-1e8;
            cur[j]=max(u,max(rd,ld));
        }
        prev=cur;
    }
    int maxi=-1e8;
    for(int j=0;j<m;j++) maxi=max(maxi,prev[j]);
    return maxi;
}

int MaxChacolates(int n,int m,vector<vector<int>>& grid){
    vector<vector<int>> front(m,vector<int>(m,0));
    vector<vector<int>> cur(m,vector<int>(m,0));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) front[j1][j2]=grid[n-1][j1];
            else front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi=-1e8;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int value=0;
                        if(j1==j2) value=grid[i][j1];
                        else value=grid[i][j1]+grid[i][j2];
                        if(j1+dj1>=0&&j1+dj1<m&&j2+dj2>=0&&j2+dj2<m) value+=front[j1+dj1][j2+dj2];
                        else value+=-1e8;
                        maxi=max(maxi,value);
                    }
                }
                cur[j1][j2]=maxi;
            }
        }
        front=cur;
    }
    return front[0][m-1];
}

bool SubSumToK(int n,int k,vector<int> &arr){
    vector<bool> prev(k+1,0),cur(k+1,0);
    prev[0]=cur[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int targ=1;targ<=k;targ++){
            bool notTake=prev[targ];
            bool take=false;
            if(arr[ind]<=targ) take=prev[targ-arr[ind]];
            cur[targ]=take||notTake;
        }
        prev=cur;
    }
    return prev[k];
}

int knapsack(vector<int> wt,vector<int> val,int n,int maxwt){
    vector<int> prev(maxwt+1,0);
    for(int w=wt[0];w<=maxwt;w++) prev[w]=val[0];
    for(int ind=1;ind<n;ind++){
        for(int w=maxwt;w>=0;w--){
            int notTake=0+prev[w];
            int take=INT_MIN;
            if(wt[ind]<=w) take=val[ind]+prev[w-wt[ind]];
            prev[w]=max(take,notTake);
        }
    }
    return prev[maxwt];
}

int MinCoins(vector<int>& nums,int targ){
    int n=nums.size();
    vector<int> prev(targ+1,0),cur(targ+1,0);
    for(int t=0;t<=targ;t++){
        if(t%nums[0]==0) prev[t]=t/nums[0];
        else prev[t]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=targ;t++){
            int nottake=0+prev[t];
            int take=INT_MAX;
            if(nums[ind]<=t) take=1+cur[t-nums[ind]];
            cur[t]=min(take,nottake);
        }
        prev=cur;
    }
    int ans=prev[targ];
    if(ans>=1e9) return -1;
    return ans;
}

int CutRod(vector<int> &price,int n){
    vector<int> prev(n+1,0);
    for(int N=0;N<=n;N++){
        prev[N]=N*price[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int notTake=0+prev[N];
            int rodlength=ind+1;
            int take=INT_MIN;
            if(rodlength<=N){
                take=price[ind]+prev[N-rodlength];
            }
            prev[N]=max(take,notTake);
        }
    }
    return prev[n];
}

int LeastCntSqStr(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int i=0;i<=m;i++) prev[i]=0;
    for(int i=1;i<=n;i++){
        cur[0]=0;
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) cur[j]=1+prev[j-1];
            else cur[j]=max(prev[j],cur[j-1]);
        }
        prev=cur;
    }
    return prev[m];
}

long long numDistinct(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<long long> dp(m+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(s[i-1]==t[j-1]) dp[j]=dp[j-1]+dp[j];
        }
    }
    return dp[m];
}

int editDist(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int j=0;j<=m;j++) prev[j]=j;
    for(int i=1;i<=n;i++){
        cur[0]=i;
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) cur[j]=prev[j-1];
            else cur[j]=1+min(prev[j],min(cur[j-1],prev[j-1]));
        }
        prev=cur;
    }
    return prev[m];
}

bool WildCardMatch(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<bool> prev(m+1,false),cur(m+1,false);
    prev[0]=true;
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=i;j++){
            if(s[j-1]!='*'){
                flag=false;
                break;
            }
        }
        cur[0]=flag;
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]||s[i-1]=='?') cur[j]=prev[j-1];
            else if(s[i-1]=='*') cur[j]=prev[j]||cur[j-1];
            else cur[j]=false;
        }
        prev=cur;
    }
    return prev[m];
}

long getMaxProfit(long *values,int n){
    vector<long> ahead(2,0),cur(2,0);
    ahead[0]=ahead[1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy) profit=max(-values[ind]+ahead[0],0+ahead[1]);
            else profit=max(values[ind]+ahead[1],0+ahead[0]);
            cur[buy]=profit;
        }
        ahead=cur;
    }
    return ahead[1];
}

int MaxProfitWithKTransac(vector<int> &prices,int n,int k){
    vector<vector<int>> after(2,vector<int>(k+1,0)),cur(2,vector<int>(k+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=k;cap++){
                if(buy==1) cur[buy][cap]=max(-prices[ind]+after[0][cap],0+after[1][cap]);
                else cur[buy][cap]=max(prices[ind]+after[1][cap],0+after[0][cap]);
            }
        }
        after=cur;
    }
    return after[1][k];
}

int MaxProfitWithCoolDown(vector<int> &prices){
    int n=prices.size();
    vector<int> front1(2,0),front2(2,0),cur(2,0);
    for(int ind=n-1;ind>=0;ind--){
        cur[1]=max(-prices[ind]+front1[0],0+front1[1]);
        cur[0]=max(prices[ind]+front2[1],0+front1[0]);
        front2=front1;
        front1=cur;
    }
    return front1[1];
}

int LongestIncreasingSubSequence(int arr[],int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    int len=1;
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
    }
    return len;
}


/*int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    int Depth=MaxDepthBT(root);
    cout<< Depth;   
    return 0;
}