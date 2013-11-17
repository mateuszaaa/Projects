fid = fopen('data.dat');
sterowanie = 255;
odpowiedz = fscanf(fid,'%d');

odpowiedz = [odpowiedz ];
wymuszenie = 5000*ones(length(odpowiedz),1)

