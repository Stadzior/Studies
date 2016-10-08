function [VertexPosition] = findVertexById(MatrixOfVertices,Id)
%Znajduje pozycjê wierzcho³ka o podanym id w macierzy, je¿eli nie ma
%zwraca -1
VertexPosition = -1;
for i=1:size(MatrixOfVertices,1);
    if (MatrixOfVertices(i,1)==Id)
        VertexPosition = i;
        break;
    end;
end;
return
end

