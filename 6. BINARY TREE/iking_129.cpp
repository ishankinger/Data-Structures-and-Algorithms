// DESERIALISE A STRING TO A GENERIC TREE

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

struct Node{
    int data;
    vector<Node*> list_children;
    Node(int val){
        data = val;
    }
};

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    for(int i=0;i<root->list_children.size();i++){
        preorder(root->list_children[i]);
    }
}

int stringToInt(string s){
    int num = 0;
    int count = 1;
    for(int i=s.size()-1;i>=0;i--){
        num += count*(s[i]-'0');
        count *= 10;
    }
    return num;
}

Node *deserialiseTreeHelper(int rootNodeValue, unordered_map<int,string> mp){
    Node* node = new Node(rootNodeValue);
    string nodeStr = mp[rootNodeValue];
    int breakPoint = nodeStr.find(':');
    int childNodes = stringToInt(nodeStr.substr(0,breakPoint));
    string childNodeStr = nodeStr.substr(breakPoint+1);
    int start = 0;
    for(int i=0;i<childNodes;i++){
        int end = childNodeStr.find(',',start);
        if(end == string::npos) end = childNodeStr.size();
        int childNodeValue = stringToInt(childNodeStr.substr(start,end));
        node->list_children.push_back(deserialiseTreeHelper(childNodeValue,mp));
        start = end+1;
    }
    return node;
}

Node* deserialiseTree(string serialisedStr){
    if(serialisedStr.empty()){
        return NULL;
    }
    unordered_map<int,string> mp;                                            // NODE_VALUE -> CHILD_NODE_STRING
    int start = 0;
    for(int i=0;i<serialisedStr.size();i++){                                 // TRAVERSING THE WHOLE STRING
        if(serialisedStr[i] == '\n'){                                        // MEANS TRAVERSE TILL FIRST STRING
            string nodeStr = serialisedStr.substr(start,i-start);            // "10:2:30,40"
            int breakPos1 = nodeStr.find(":");                               // BREAK_POINT_1 = 2
            int nodeValue = stoi(nodeStr.substr(0,breakPos1));               // EXTRACING NODE VALUE AS 10
            mp[nodeValue] = nodeStr.substr(breakPos1 + 1);                   // EXTRACTNG CHILD NODES AS A STRING AND STORING IN MAP
            start = i+1;                                                     // START TO UPDATE FOR FURTHER STRING INPUTS IN NEXT LINES
        }
    }
    int rootNodeValue = stringToInt(serialisedStr.substr(0,serialisedStr.find(":")));
    return deserialiseTreeHelper(rootNodeValue,mp);
}

int main(){
    string serialisedStr = "1:3:2,3,6\n2:0:\n3:2:4,5\n4:0:\n5:0:\n6:1:9\n9:0:";
    Node* root = deserialiseTree(serialisedStr);
    preorder(root);

    return 0;
}