function [w,b] = LearnPerceptron()
%
vertices = [[-9,-10];[-8,20];[-6,5];[2,20];[4,25];[5,9];[4,-16];[1,-10];[-2,-10];[-6,-25]];
wagesHasChanged = true;
w = rand();
b = rand();
t = [1,1,1,1,1,0,0,0,0,0];
counter = 0;
while wagesHasChanged == true;
    if (counter>100)
        disp('Zbiór nie separowalny liniowo.');
        break;
    end;
    counter = counter + 1;
    wagesHasChanged = false;
    for i=1:size(vertices,1)    
        a = w*vertices(i,1)+w*vertices(i,2) + b;
        if(a>0)
            y = 1;
        else
            y = 0;
        end;
        e = t(i) - y;
        if(e ~= 0)
            wagesHasChanged = true;
            w = w+(e*vertices(i,1))+(e*vertices(i,2));
            b = b+e;
        end;
    end;
end;
line([-20 20],[-20*w+b 20*w+b],'Color','green');
hold on;
for i=1:size(vertices,1)
    if(t(i)==1)
        plot(vertices(i,1),vertices(i,2),'r.','MarkerSize',20) 
    else
        plot(vertices(i,1),vertices(i,2),'b.','MarkerSize',20) 
    end;
end;
return
end

