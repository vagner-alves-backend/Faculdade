const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");

canvas.style.background = "#ff8";

let animation;
let position_x = 23;
let position_y = 23;

let voltas = 1;
let color= "rgba(241, 85, 255, 1)";
function desenha() {
    ctx.clearRect(0, 0, 500, 500);
    
    ctx.beginPath();
    ctx.lineWidth = 4;
    ctx.fillStyle = color;
    ctx.arc(position_x, position_y, 20, 0, Math.PI * 2, false);
    ctx.fill();
    
    switch (voltas) {
        case 1:
            position_x+=2;
            if (position_x >= 470){
                color = "rgba(241, 85, 255, 1)";
                voltas = 2;                
            }
            break;
        case 2:
            position_y+=2;
            if (position_y >= 470) {
                color = "rgba(255, 85, 159, 1)";
                voltas = 3
            }
            break;
        case 3:
            position_x-=2;
            if (position_x < 30) {
                color = "rgba(255, 85, 85, 1)";
                voltas = 4;
            }
            break;
        case 4:
            position_y-=2;
            if (position_y < 30) {
                color = "rgba(252, 43, 43, 1)";
                voltas = 1;
            }
            break;
    }
   

    animation = requestAnimationFrame(desenha);    
}

