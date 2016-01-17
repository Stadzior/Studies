import graphs
from PIL import Image

im=Image.open("zdj.jpg")
h=im.histogram()

m = input("Podaj na ile chcesz dzielic:")
print m

R=h[0:256]
G=h[256:512]
B=h[512:768]

mLength = 256/m

Rhist = map(lambda x: sum(R[x*mLength:(x+1)*mLength]),range(m))
Ghist = map(lambda x: sum(G[x*mLength:(x+1)*mLength]),range(m))
Bhist = map(lambda x: sum(B[x*mLength:(x+1)*mLength]),range(m))

graph = graphs.BarGraph('vBar')
graph.labels = str(range(1,m+1)).replace('[','').replace(']','')
graph.titles = ['Class', 'Values']
graph.values = zip(Rhist,Ghist,Bhist)
graph.barColors =['#FF0000','#00FF00','#0000FF']
graph.legend = ['R', 'G','B']

f=open("Wykres.html","w")
f.write(graph.create())
f.close()
