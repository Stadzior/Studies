function [isCrossing]= isCrossing(x11,y11,x12,y12,x21,y21,x22,y22)
%Sprawdzanie czy dane linie siê przecinaj¹
    isCrossing = false;
%line1
x1  = [x11 x12];
y1  = [y11 y12];

%line2
x2 = [x21 x22];
y2 = [y21 y22];

%fit linear polynomial
p1 = polyfit(x1,y1,1);
p2 = polyfit(x2,y2,1);

%calculate intersection
x_intersect = fzero(@(x) polyval(p1-p2,x),3);
y_intersect = polyval(p1,x_intersect);

if (x11>x12)
    x1Up = x11;
    x1Down = x12;
else
    x1Up = x12;
    x1Down = x11;
end;

if (x21>x22)
    x2Up = x21;
    x2Down = x22;
else
    x2Up = x22;
    x2Down = x21;
end;

if (y11>y12)
    y1Up = y11;
    y1Down = y12;
else
    y1Up = y12;
    y1Down = y11;
end;

if (y21>y22)
    y2Up = y21;
    y2Down = y22;
else
    y2Up = y22;
    y2Down = y21;
end;
if (x1Up>x_intersect>x1Down) && (x2Up>x_intersect>x2Down) && (y1Up>y_intersect>y1Down) && (y2Up>y_intersect>y2Down)
        isCrossing = true;
end;
    return;
end

