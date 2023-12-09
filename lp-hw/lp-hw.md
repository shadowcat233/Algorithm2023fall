# 线性规划作业
王静初 2021K8009918003
## 第一题
### 题目
You want to determine the quantities x1, x2, ..., xn of n different foods, each containing m types of nutrients. The amount of the i-th nutrient in the j-th food is represented as $a_{ij}$, and the prices of the n foods are c1, c2, ..., cn. Your goal is to find a recipe where the content of each of the m nutrients is at least b1, b2, ..., bm, while minimizing the total cost.  
### 解答
LP Formulation:  
$min\sum_{j=1}^{n}x_{j}c_{j}\quad s.t.$  
$\sum_{j=1}^{n}x_{j}a_{ij}\ge b_{i}\quad $for each i in {1,...,m};  
$x_{j}\ge 0 \quad$for each j in {1,...,n}  
## 第二题
### 题目
You now need to pack dormitory items. You have m items and n boxes, with enough boxes to accommodate all items. The space occupied by the i-th item is Ci, and the capacity of the j-th box is Sj . Your goal is to pack all items using as few boxes as possible.  
### 作答
$x_{j}$表示第j个箱子是否被使用，$y_{ij}$表示第i个物品是否被装在第j个箱子里，为1表示是。  
LP Formulation:  
$min\sum_{j=1}^{n}x_{j}\quad s.t$  
$\sum_{j=1}^{n}y_{ij}=1 \quad$for each i in {1,...,m}  
$\sum_{i=1}^{m}y_{ij}C_{i}\leq S_{j}\quad$for each j in {1,...,n}    
$y_{ij}=0/1, x_{j}=0/1 \quad$for each i and j  
$m\times x_{j}\geq \sum_{i=1}^{m}y_{ij} \quad$for each i and j  
其中最后一个约束条件保证了$\sum_{i=1}^{m}y_{ij}$为0时$x_{j}$可以为0，$\sum_{i=1}^{m}y_{ij}$大于0时$x_{j}$只能为1.
## 第三题
### 题目
On a farm, there are two different crops: wheat and soybeans. Planting one acre of wheat requires 5 units of fertilizer and 2 units of water, while planting one acre of soybeans requires 3 units of fertilizer and 4 units of water. The farm has 30 units of fertilizer and 20 units of water available.Each acre of wheat can be sold for 150 dollars, and each acre of soybeans can be sold for 120 dollars. The farm owner wants to maximize the total income.  
### 作答
$x_{1}$表示种小麦的亩数，$x_{2}$表示种大豆的亩数。  
LP Formulation:  
$max(150x_{1}+120x_{2})\quad s.t.$  
$5x_{1}+3x_{2}\leq 30$  
$2x_{1}+4x_{2}\leq 20$  
$x_{1}\geq 0,\quad x_{2}\geq 0$  
## 第四题
### 题目
The company manufactures three products, A1, A2, and A3, utilizing resources such as metal sheets, labor, and machinery. The quantities of various resources required to manufacture one unit of each product are provided in the table below. Without considering fixed costs, the unit profits for each product are 40,000 yuan, 50,000 yuan, and 60,000 yuan, respectively. Available resources include 500 tons of metal sheets, 300 workers per month, and 100 machines per month. In addition to production, fixed costs must be paid: 1 million yuan for A1, 1.5 million yuan for A2, and 2 million yuan for A3. Develop a production plan for the company to maximize profits.
|Resources|A1|A2|A3|
|---------|--|--|--|
|Metal sheets/t|2|4|8|
|Labor force (person/month)|2|3|4|
|Machinery (units/month)|1|2|3|  
### 作答
$x_{i}$表示生产$A_{i}$的数量，$y_{i}$表示是否生产$A_{i}$.  
LP Formulation:
$max(40000x_{1}+50000x_{2}+60000x_{3}-(1000000y_{1}+1500000y_{2}+2000000y_{3}))\quad s.t.$  
$2x_{1}+4x_{2}+8x_{3}\leq 500 \quad$  (1)  
$2x_{1}+3x_{2}+4x_{3}\leq 300 \quad$  (2)  
$x_{1}+2x_{2}+3x_{3}\leq 100 \quad$  (3)  
$x_{i}\geq 0 \quad$for each i  
$100\times y_{i}\geq x_{i} \quad$for each i and j (4)  
其中(4)保证了$x_{i}$为0时$y_{i}$可以为0，$x_{i}$大于0时$y_{i}$只能为1. 它的前提是$x_{i}\leq 100$，这个条件是从(1)(2)(3)中得出的。
## 第五题
### 题目
The company plans to open branches in four districts in the urban area, with a total of 10 locations to choose from. Taking into account the consumption levels and residential density of residents in each district, the following rules are established:
In District 1, at most two points can be selected from A1, A2, and A3;
In District 2, at least one point must be selected from A4 and A5;
In District 3, at least one point must be selected from A6 and A7;
In District 4, at least two points must be selected from A8, A9, and A10.
The investment and annual profit for each point Aj vary depending on the location, as shown in the table below. The total investment of the company should not exceed 7.2 million yuan. Which sales points should be selected to maximize the company’s annual profit?
||A1|A2|A3|A4|A5|A6|A7|A8|A9|A10|
|--|--|--|--|--|--|--|--|--|--|--|
|Investment|100|120|150|80|70|90|80|140|160|180|
|Profit|36|40|50|22|20|30|25|48|58|61|  
### 作答
$x_{i}$表示是否投资$A_{i}$点。$I_{i}$表示$A_{i}$点需要投资的金额，$P_{i}$表示$A_{i}$点可以获得的利润。  
LP Formulation:  
$max\sum_{i=1}^{10}x_{i}P_{i} \quad s.t.$  
$\sum_{i=1}^{10}x_{i}I_{i} \leq 720$  
$x_{1}+x_{2}+x_{3}\leq 2$  
$x_{4}+x_{5}\geq 1$  
$x_{6}+x_{7}\geq 1$  
$x_{8}+x_{9}+x_{10}\geq 2$  
$x_{i}=0/1 \quad$for each i  
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>
