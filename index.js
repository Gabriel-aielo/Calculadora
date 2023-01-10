function calcular (tipo, valor) {
    
    if (tipo === 'acao'){

        switch (valor) {

            case '+':document.getElementById('input').value += valor; break
            
            case '-':document.getElementById('input').value += valor; break

            case'*':document.getElementById('input').value += valor; break

            case'c':document.getElementById('input').value = ''  ; break

            case'/':document.getElementById('input').value += valor; break

            case'.':document.getElementById('input').value += valor; break

            default: //mostrar resultado

            var resultado = document.getElementById('input').value
                
                document.getElementById('input').value = eval(resultado)
           
            return resultado;
        }
    }else if(tipo ==='valor'){
        document.getElementById('input').value += valor;
    }else if(resultado === 0){
        document.getElementById('input').value = 0;
    }else{
        alert('erro')
    }


    
}