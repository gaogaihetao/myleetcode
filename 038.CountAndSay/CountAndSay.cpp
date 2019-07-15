string countAndSay(int n) {
    string ou = "1";
    while(--n) {
        ou = next(ou);
    }
    return ou;
}

string next(string& in) {
    string ou = "";
    for(int i=0; i<in.size();) {
        char tmp = in[i];
        int count=1;
        int j=i+1;
        for(j;j<in.size();j++){
            if(tmp==in[j]){
                count++;
            } else {
                break;
            }
        }
        ou.append(to_string(count));
        ou.append(string(1,tmp));
        i = j;
    }
    return ou;
}