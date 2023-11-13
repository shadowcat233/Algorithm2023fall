# 贪心算法作业
2021K8009918003 王静初  
## 第一题 Commando War 
### 思路
对士兵的讲解是顺序进行的，而士兵们的行动是并行的。  
因此，从一开始，对士兵讲解所花时间的总和就是确定的，我们假定为m。假设最后一个士兵需要执行的任务耗时k秒，那么总时间至少为m+k秒。  
至此，一个贪心的想法产生了：不妨让最后那个士兵执行耗时最短的任务，让总时间的下限尽量低一些。如果存在多个执行时间同样最短的任务，那么选择哪一个都可以：不论怎么选，总讲解时间是相同的，最后一个任务执行完成的时间也是相同的。  
用数组brief和exec分别表示讲解和执行的时间，且执行时间最短的任务标号为i。既然已经确定了最后一个任务，假设倒数第二个要执行的任务标号为j，那么可以知道结束讲解这个任务的时间为m-brief[i]，任务完成的时间为m-brief[i]+exec[j].让任务完成的时间尽量短即可。  
由此可以看出，只要按执行时间长短排序，使执行时间越长的任务越先执行即可。
### 伪代码
```
// 为方便排序，使用数据结构
typedef struct{
    brief;
    exec;
}task; 

// 排序判断
function cmp(a,b)
return a.exec>b.exec;
end function

// 输入为n个task的数组tasks，输出为最短完成时间
function CommandoWar(n,tasks)
b_time=0;
for i=0 to n-1 do:
    b_time+=tasks[i].brief;
end for
sort(tasks,tasks+n,cmp);
done_time=INT_MAX;
for i=n-1 to 0 do:
    done_time=max(done_time,b_time+tasks[i].exec);
    b_time-=tasks.brief[i];
end for
return done_time;
end function 
```
### 正确性证明
现在tasks数组以按exec从大到小的顺序排序好，并按上述伪代码算出了结果done_time。假设tasks[n-1]不是在最后一个执行：  
1.如果$done\_time=tasks[n-1].exec+\sum_{i=0}^{n-1}tasks[i].brief$，显然更改位置后的时间会延长。  
2.如果$done\_time=tasks[j-1].exec+\sum_{i=0}^{j-1}tasks[i].brief$，那么tasks[n-1]必须换到tasks[j]及之前的位置才可能使结果改变。假设换到了位置k（k<=j），这样的话，位置k之前的完成时间不变，位置k后的完成时间增加tasks[n-1].brief。总完成时间延长。  
故tasks[n-1]最后一个执行是最优解之一。递归来看tasks[n-2]、tasks[n-3]...可知按排序顺序排列即为最优解之一（最优解可能不唯一）。
### 算法复杂度
时间复杂度为$O(logn)$：排序需$O(logn)$，计算done_time需$O(n)$.  
空间复杂度为$O(n)$：仅需保存tasks数组。如果不算tasks数组的话空间复杂度为$O(1)$.
## 第二题 DNA Consensus String
### 伪代码
```
function char2num(c)
if c=='A' then return 0;
if c=='C' then return 1;
if c=='G' then return 2;
else return 3;
end function

function num2str(num)
static const string arr[4]={"A","C","G","T"};
return arr[num];

function DNAConsensusString(dna,m,n) //dna[m][n]
cnt[4]={0};
str="";
dist=0；
for i=0 to n-1 do:
    for j=0 to 3 do:
        cnt[j]=0;
    end for
    max=0;
    min_k=4;
    for j=0 to m-1 do:
        k=char2num(dna[j][i]);
        cnt[k]++;
        if cnt[k]>max then
            max=cnt[k];
            min_k=k;
        end if
        else if cnt[k]==max&&k<min_k then
            min_k=k;
        end else if
    end for
    str+=num2str(min_k);
    dist+=m-max;
end for
print(str);
print(dist);
end function
```
### 算法复杂度
时间复杂度为$O(m*n)$：对dna数组遍历一遍即可。  
不算dna数组的话，空间复杂度为$O(1)$.
## 第三题 Opponents
water
### 伪代码
```
function Opponents(opnts,m,n)
fail=1;
maxlen=0;
i=j=0;
for j=0 to n-1 do:
    fail=1;
    for k=0 to m-1 do:
        fail&=opnts[k][j];
    end for
    if fail==1 then:
        i=j+1;
    end if
    else then:
        maxlen=max(maxlen,j-i+1);
    end else
end for
return maxlen;
end function
```
## 第四题 Minimum Varied Number
123456789water
### 伪代码
```
function MinimumVariedNumber(num)
dgt=9;
ans=0;
while num>0&&dgt>0 do:
    if num>=dgt then:
        num-=dgt;
        ans=ans*10+dgt;
        dgt--;
    end if
    else then:
        ans=ans*10+num;
        num=0;
    end else
end while
if num>0 then return -1;
return ans;
end function
```
## 第五题 Joey Takes Money[^1]
直接累乘water
### 伪代码
```
function JoeyTakesMoney(money,n)
mul=1;
for i=0 to n-1 do:
    mul*=money[i];
end for
return (mul+n-1)*2022;
end function
```
[^1]:RIP Chandler Muriel Bing