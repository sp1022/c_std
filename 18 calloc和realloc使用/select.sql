select 
sum(case when sfzz1='是' then 1 else 0 end) ||' (占比）'|| round(sum(case when sfzz1='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "发烧",
sum(case when sfzz2='是' then 1 else 0 end) ||'(占比） '|| round(sum(case when sfzz2='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"头疼",
sum(case when sfzz3='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz3='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "全身酸痛",
sum(case when sfzz4='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz4='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "呕吐拉肚子",
sum(case when sfzz5='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz5='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "鼻塞",
sum(case when sfzz6='是' then 1 else 0 end) ||' (占比）'|| round(sum(case when sfzz6='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"咳嗽",
sum(case when sfzz7=' 是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz7='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text  "胸闷",
sum(case when sfzz8='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz8='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "味觉消失", 
sum(case when sfjy='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfjy='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "就医",
count(1) "样本人数"
from t_kymd;


select 
sum(case when sfzz1='是' then 1 else 0 end) ||' (占比）'|| round(sum(case when sfzz1='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "发烧",
sum(case when sfzz2='是' then 1 else 0 end) ||'(占比） '|| round(sum(case when sfzz2='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"头疼",
sum(case when sfzz3='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz3='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "全身酸痛",
sum(case when sfzz4='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz4='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "呕吐拉肚子",
sum(case when sfzz5='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz5='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "鼻塞",
sum(case when sfzz6='是' then 1 else 0 end) ||' (占比）'|| round(sum(case when sfzz6='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"咳嗽",
sum(case when sfzz7=' 是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz7='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text  "胸闷",
sum(case when sfzz8='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz8='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "味觉消失", 
sum(case when sfjy='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfjy='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "就医",
count(1) "样本人数",
xb "性别"
from t_kymd
group by xb;


select 
sum(case when sfzz1='是' then 1 else 0 end) ||' (占比）'|| round(sum(case when sfzz1='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "发烧",
sum(case when sfzz2='是' then 1 else 0 end) ||'(占比） '|| round(sum(case when sfzz2='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"头疼",
sum(case when sfzz3='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz3='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "全身酸痛",
sum(case when sfzz4='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz4='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "呕吐拉肚子",
sum(case when sfzz5='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz5='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "鼻塞",
sum(case when sfzz6='是' then 1 else 0 end) ||' (占比）'|| round(sum(case when sfzz6='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"咳嗽",
sum(case when sfzz7=' 是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz7='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text  "胸闷",
sum(case when sfzz8='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfzz8='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "味觉消失", 
sum(case when sfjy='是' then 1 else 0 end)||' (占比）'|| round(sum(case when sfjy='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "就医",
count(1) "样本人数",
case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end "年龄分布"
from t_kymd
group by case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end;


select 
sum(case when sfzz1='否' and sfzz2='否' and sfzz3='否'and sfzz4='否'and sfzz5='否'and sfzz6='否'and sfzz7='否' and sfzz8='否' then 1 else 0 end)  "无症状喜洋洋", 
sum(case when sfzz3='是' and zz3ts::numeric>1 then 1 else 0 end)  "酸痛懒洋洋(酸痛大于1天)", 
sum(case when sfzz1='是' and zz1cd ='低烧反复' and zz1ts::numeric>2 then 1 else 0 end)  "低烧暖洋洋(烧两天以上)", 
sum(case when sfzz1='是' and zz1cd ='高烧反复' and zz1ts::numeric>2 then 1 else 0 end)  "高烧暖洋洋(烧两天以上)",
count(1) "样本人数"
from t_kymd;


select 
sum(case when sfzz1='否' and sfzz2='否' and sfzz3='否'and sfzz4='否'and sfzz5='否'and sfzz6='否'and sfzz7='否' and sfzz8='否' then 1 else 0 end)  "无症状喜洋洋", 
sum(case when sfzz3='是' then 1 else 0 end)  "酸痛懒洋洋", 
sum(case when sfzz1='是' and zz1cd ='低烧反复' then 1 else 0 end)  "低烧暖洋洋", 
sum(case when sfzz1='是' and zz1cd ='高烧反复' then 1 else 0 end)  "高烧暖洋洋",
count(1) "样本人数"
from t_kymd;


--bg3
select 
ymcj "疫苗厂家",
count(1) "人数",
round(sum(case when sfzz1='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "发烧",
round(sum(case when sfzz2='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"头疼",
round(sum(case when sfzz3='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "全身酸痛",
round(sum(case when sfzz4='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "呕吐拉肚子",
round(sum(case when sfzz5='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "鼻塞",
round(sum(case when sfzz6='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"咳嗽",
round(sum(case when sfzz7='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text  "胸闷",
round(sum(case when sfzz8='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "味觉消失", 
round(sum(case when sfjy='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "就医"
from t_kymd
group by ymcj;


--
select 
case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end "年龄分布",
xb "性别",
count(1) "人数",
round(sum(case when sfzz1='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "发烧",
round(sum(case when sfzz2='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"头疼",
round(sum(case when sfzz3='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "全身酸痛",
round(sum(case when sfzz4='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "呕吐拉肚子",
round(sum(case when sfzz5='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "鼻塞",
round(sum(case when sfzz6='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"咳嗽",
round(sum(case when sfzz7='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text  "胸闷",
round(sum(case when sfzz8='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "味觉消失", 
round(sum(case when sfjy='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "就医"
from t_kymd
group by case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end,xb
order by case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end ,xb
--bg2
select 
case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end "年龄分布",
xb "性别",
ymcj "疫苗厂家",
count(1) "人数",
round(sum(case when sfzz1='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "发烧",
round(sum(case when sfzz2='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"头疼",
round(sum(case when sfzz3='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "全身酸痛",
round(sum(case when sfzz4='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "呕吐拉肚子",
round(sum(case when sfzz5='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "鼻塞",
round(sum(case when sfzz6='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"咳嗽",
round(sum(case when sfzz7='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text  "胸闷",
round(sum(case when sfzz8='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "味觉消失", 
round(sum(case when sfjy='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "就医"
from t_kymd
group by case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end,xb,ymcj
order by case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end ,xb,ymcj;


select 
 ymcj "疫苗厂家",
case 
when  date_trunc('month',dszsj::timestamp)>='2021-6-1' and  date_trunc('month',dszsj::timestamp)<'2022-1-1' then '2021下半年'
when  date_trunc('month',dszsj::timestamp)>='2022-1-1' and  date_trunc('month',dszsj::timestamp)<'2022-6-1' then '2022上半年'
when  date_trunc('month',dszsj::timestamp)>='2022-6-1' and  date_trunc('month',dszsj::timestamp)<'2023-6-1' then '2022下半年'
end "第三针疫苗接种区间",
count(1) "人数",
round(sum(case when sfzz1='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "发烧",
round(sum(case when sfzz2='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"头疼",
round(sum(case when sfzz3='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "全身酸痛",
round(sum(case when sfzz4='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "呕吐拉肚子",
round(sum(case when sfzz5='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "鼻塞",
round(sum(case when sfzz6='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"咳嗽",
round(sum(case when sfzz7='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text  "胸闷",
round(sum(case when sfzz8='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "味觉消失", 
round(sum(case when sfjy='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "就医"
from t_kymd 
where dszsj <>'' 
group by ymcj,
case 
when  date_trunc('month',dszsj::timestamp)>='2021-6-1' and  date_trunc('month',dszsj::timestamp)<'2022-1-1' then '2021下半年'
when  date_trunc('month',dszsj::timestamp)>='2022-1-1' and  date_trunc('month',dszsj::timestamp)<'2022-6-1' then '2022上半年'
when  date_trunc('month',dszsj::timestamp)>='2022-6-1' and  date_trunc('month',dszsj::timestamp)<'2023-6-1' then '2022下半年'
end




--bg4
select 
ymcj "疫苗厂家",
xb "性别",
count(1) "人数",
round(sum(case when sfzz1='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "发烧",
round(sum(case when sfzz2='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"头疼",
round(sum(case when sfzz3='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "全身酸痛",
round(sum(case when sfzz4='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "呕吐拉肚子",
round(sum(case when sfzz5='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "鼻塞",
round(sum(case when sfzz6='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text"咳嗽",
round(sum(case when sfzz7='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text  "胸闷",
round(sum(case when sfzz8='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "味觉消失", 
round(sum(case when sfjy='是' then 1 else 0 end)/count(1)::numeric *100,2) ::text "就医"
from t_kymd
group by ymcj,xb;







select 
"年龄分布",
"性别",
sum("低烧反复")over(partition by "年龄分布")
from (select 
case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end "年龄分布",
xb "性别", 
count(case when zz1cd='低烧反复' then 1  end)"低烧反复",
count(case when zz1cd='高烧反复' then 1 end) "高烧反复",
count(case when zz1cd='低烧+高烧反复' then 1 end) "低烧+高烧反复",
count(case when zz1cd='无' then 1 end) "无发烧"
from t_kymd
group by case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end,xb
order by case when nl::numeric>=20 and nl::numeric<30 then '年龄25-30'  when nl::numeric>=30 and nl::numeric<35 then '年龄30-35' when nl::numeric>=35 then '年龄35以上' end ,xb)foo