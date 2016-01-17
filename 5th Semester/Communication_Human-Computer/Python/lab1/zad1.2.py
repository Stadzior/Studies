#Python 3.5.0
# -*- coding: cp1250 -*-
#Kamil Stadryniak 187803
#Grupa: wtorek 8:15
import re

listInputtedData = input("Wprowadź dwa adresy IP oddzielone spacją.\n").split(' ')

BinIP1 = list("".join(map(lambda octet: str(bin(int(octet)))[2:].zfill(8),listInputtedData[0].split('.'))))
BinIP2 = list("".join(map(lambda octet: str(bin(int(octet)))[2:].zfill(8),listInputtedData[1].split('.'))))
MatchedBits = list(map(lambda bit1,bit2: 1-abs(int(bit1)-int(bit2)),BinIP1,BinIP2))
if 0 in MatchedBits:
    Mask = list(map(int,'1'*MatchedBits.index(0)+'0'*(32-MatchedBits.index(0))))
    Net = ".".join(list(map(lambda octet: str(int(octet,2)),(re.findall('........',"".join(list(map(lambda bit,isMask: str(bit) if bool(isMask) else '0',BinIP1,Mask))))))))
    print(Net+" "+str(MatchedBits.index(0)))
    
input("Naciśnij dowolny klawisz")
