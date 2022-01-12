
let flipImage = (image) =>{
    //reversing it horizontally
    for(let i=0;i<rows;i++){
        for(let j=0;j<cols/2;j++){
            let temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }

    //inverting i.e 0 to 1 and 1 to 0 using ! operator
    for(let i=0;i<rows;i++){
        for(let j=0;j<cols;j++){
            image[i][j] = !image[i][j];
        }
    }
    return image;
}


//sample test case
let image = [[1,1,0],[1,0,1],[0,0,0]];

let rows = image.length;
let cols = image[0].length;

image = flipImage(image);

for(let i=0;i<rows;i++){
    for(let j=0;j<cols;j++){
        console.log(image[i][j]);
    }
}




