ll arr[n];
        if(arr[0]>=0){
            ll mn=LLONG_MIN;
            if(arr[n-1]<0){
                for(int j=n-2;j>=0;j--){
                    if(arr[j]>=0){
                        mn=min(arr[j],mn);
                        break;
                    }
                    else mn=min(mn,abs(arr[j]));
                }
                for(int i=0;i<n;i++)x=x+abs(arr[i]);
                x=x-mn;
            }
            else{
                for(int i=0;i<n-1;i++)x=x+abs(arr[i]);
            }
        }
        else{
            ll mn=0;
            ll cnt1 = arr[0];
            ll real[n];
            for(int i=n-2;i>=1;i--){
                real[i]=arr[i+1]+real[i+1];
            }
            if(arr[n-1]<0){
                ll suff[n];
                for(int j=n-2;j>=0;j--){
                    if(arr[j]>=0){
                        mn=min(arr[j],mn);
                        break;
                    }
                    else mn=min(mn,abs(arr[j]));
                }
                suff[n-1]=abs(suff[n-1]);
                for(int i=n-2;i>=1;i--){
                    suff[i]=abs(arr[i])+suff[i+1];
                }
                real[n-1]=arr[n-1];

                for(int i=1;i<n;i++){
                    if(arr[i]<0)x=x+abs(arr[i]);
                    else{
                        if(cnt1+suff[i]-mn >= real[i]){
                            x=x+cnt1+suff[i]-mn;
                            break;
                        }
                        else{
                            x=x-arr[i];
                            continue;
                        }
                    }
                }
            }
            else{
                ll suff[n];
                ll cnt1=arr[0];
                suff[n-2]=abs(arr[n-2]);
                for(int i=n-3;i>=0;i--){
                    suff[i]=abs(arr[i])+suff[i+1];
                }
                for(int i=1;i<n-1;i++){
                    if(arr[i]<0)x=x+abs(arr[i]);
                    else {
                        if(suff[i]+cnt >=real[i] ){
                            x=x+cnt1+suff[i];
                            break;
                        }
                        else {
                            x=x-arr[i];
                            continue;
                        }
                    }
                }
            }
        }
        cout<<x<<endl;