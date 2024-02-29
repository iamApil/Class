


const userNameValidate = () => {
    let username = document.getElementsByClassName("username").value

    if (username == "") {
        document.getElementsByClassName("user-validate").innerHTML = "Username is ok"
    }
    else {
        document.getElementsByClassName("user-validate").src
    }
}