function colorChange() {
    // var randomColor =( Math.random(Math.random(0,10))).toString(16)
    // console.log(randomColor)
    // console.log(Math.random(1,2))
    //  console.log('#'+Math.floor(Math.random()*10000000).toString(16))
    // Actual Working
    // console.log('#'+Math.floor(Math.random()*10000000))

    var randomColor = ('#'+Math.floor(Math.random()*10000000).toString(16)) 
    console.log(randomColor)


     document.getElementById("container").style.backgroundColor = randomColor

     document.getElementById("showHexCode").innerHTML = randomColor

    

   

 
    
   
}