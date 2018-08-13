/**
 * 
 * @param {number} a 
 * @param {number} b 
 * @param {number} c 
 * @param {number} d 
 * @param {number} e 
 * @param {number} f 
 * @param {number} g 
 * @param {number} h 
 * @param {number} m 
 * @param {number} n 
 * @param {number} p 
 * @param {number} q 
 */
function sistemSolver(a, b, c, d, e, f, g, h, m, n, p, q){
    let mem1 = a*f-e*b;
    let mem2 = e*n-m*f;
    var x3 = (mem1*(q*e-m*h) - mem2*(h*a-d*e)) / (mem1*(e*p-m*g) - mem2*(a*g-e*c));
    x3 = x3.toFixed(4);
    var x2 = (a*h-e*d-(g*a-c*e)*x3)/(f*a-e*b);
    x2 = x2.toFixed(4);
    var x1 = h/e - (f/e)*x2 - (g/e)*x3;
    x1 = x1.toFixed(4);
    let result = [(x1%1==0)?parseInt(x1):x1, (x2%1==0)?parseInt(x2):x2, (x3%1==0)?parseInt(x3):x3];
    return result;
}

function calculateResults(e){
    // Avoid Page to reload
    e.preventDefault();
    equation1 = document.getElementsByClassName("equation-1");
    equation2 = document.getElementsByClassName("equation-2");
    equation3 = document.getElementsByClassName("equation-3");
    for (var i = 0; i < 4; i++){
        if (equation1[i].value === '' || equation2[i].value === '' || equation3[i].value === ''){
            alert('Ingresa números por favor');
            window.location.reload();
            return;
        }
    }
    // No errors were found
    results = sistemSolver(parseInt(equation1[0].value), parseInt(equation1[1].value), parseInt(equation1[2].value), parseInt(equation1[3].value), parseInt(equation2[0].value), parseInt(equation2[1].value), parseInt(equation2[2].value), parseInt(equation2[3].value), parseInt(equation3[0].value), parseInt(equation3[1].value), parseInt(equation3[2].value), parseInt(equation3[3].value));
    resultSpans = document.getElementsByClassName("result");
    for (var i = 0; i < 3; i++){
        resultSpans[i].firstChild.innerHTML = "x"+(i+1) + " = " + results[i];
    }   
}