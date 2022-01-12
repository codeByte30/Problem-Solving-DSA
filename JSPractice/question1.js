//brute force approach
// let findRepeated = (arr) => {
//     for(let i=0;i<arr.length;i++){
//         let count = 0;
//         for(let j=i+1;j<arr.length;j++){
//             if(arr[i] === arr[j]){
//                 count++;
//             }
//         }
//         if(count+1==arr.length/2){
//             return arr[i];
//         }
//     }
//     return -1;
// }


let findRepeated = (arr) =>{
    let count = [];
    for(let num of arr){
        count[num] = count[num] ? count[num] + 1 : 1;
    }
    let ans;
    for(let i=0;i<count.length;i++){
        if(count[i] == arr.length/2){
            ans = i;
            break;
        }
        // console.log(count[i]);
    }
    return ans;
}


// let arr = [5,1,5,2,5,3,5,4];
// let arr = [2,1,2,5,3,2];
// let arr = [1,2,3,3];
console.log(findRepeated(arr));