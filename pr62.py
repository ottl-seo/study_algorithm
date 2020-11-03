# -*- coding: cp949 -*-

# --- 리스트 단어 길이의 평균 구하는 함수 ---
def get_avg(data): 
    sum=0
    for d in data:
        sum+=float(len(d))
    avg=float(sum/len(data)) #평균 길이
    return avg

# --- 평균길이와 가장 가까운 단어를 찾는 함수 ---
def word_length(data): 

    avg=get_avg(data) #리스트 속 단어길이의 평균을 구한다
    
    near=data[0] #평균과 가장 가까운 길이의 단어- 일단 첫번째 단어로 지정
    
    for d in data:
        near_len=abs(float(len(near))-avg)
        
        if(near_len>abs(float(len(d))-avg)):
            near=d
    return near
            
# --- main ---
data=["apple","cat","blue","air","an","school"]
print(data)
print("길이 평균= "+str(get_avg(data)))
print(word_length(data))
