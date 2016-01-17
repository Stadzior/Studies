from pyx import *
import csv
import time

currencyList = ['dolar','euro','frank']
graphDataList = []
values = []
dates = []
for currency in currencyList:

    print('\nKURS '+currency.upper()+'\n')
    with open(currency+'.csv','r')as file:
        reader = csv.reader(file,delimiter=';')
        reader = list(reader)
    for row in reader:
        if len(row) == 4:
            print(row[:3])
            try:
                values.append(float(row[1]))
                dates.append(time.mktime(time.strptime(row[0], "%Y-%m-%d")))
            except ValueError:
                pass
    graphDataList.append(graph.data.values(title=currency, x=dates[::-1],y=values[::-1]))
    values.clear()
    dates.clear()
    
g = graph.graphxy(width=8,
                  x=graph.axis.linear(min=time.mktime(time.strptime(reader[len(reader)-5][0], "%Y-%m-%d")), max=time.mktime(time.strptime(reader[3][0], "%Y-%m-%d"))),
                  y=graph.axis.linear(title="wartosc (PLN)",min=3.5, max=4.5),
                  key=graph.key.key(pos="br", dist=0.1))
g.plot(graphDataList,
       [graph.style.line([color.gradient.Rainbow])])          
filename = "wykres.pdf"

c = canvas.canvas()
c.insert(g)
rect = path.path(path.moveto(-0.25, -0.7),
              path.lineto(-0.25, -0.1),
              path.lineto(7.75, -0.1),
              path.lineto(7.75, -0.7),
              path.closepath())
c.fill(rect,[color.rgb(1,1,1)])
c.text(-0.4,-0.5,str(reader[len(reader)-5][0])[5:])
c.text(7.6,-0.5,reader[3][0][5:])
c.writePDFfile("wykres.pdf")

input("\nPomyślnie wygenerowano wykres do pliku "+filename)


