function distanciaAbsoluta(numero1, numero2) {
  if (numero1 === numero2) {
    return 0;
  } else if (numero1 > numero2) {
    return numero1 - numero2;
  } else {
    return numero2 - numero1;
  }
}

function encontrarMenorDistancia(array1, array2) {
  let menorDistancia = Infinity;
  let indiceA = null;
  let indiceB = null;

  for (let i = 0; i < array1.length; i++) {
    for (let j = 0; j < array2.length; j++) {
      //console.log(array1[i] + "i");
      //console.log(array2[j] + "j");
      const distanciaAtual = distanciaAbsoluta(array1[i], array2[j]);
      

      if (distanciaAtual < menorDistancia) {
        menorDistancia = distanciaAtual;
        indiceA = i;
        indiceB = j;
      }
    }
  }

  return {
    menorDistancia: menorDistancia,
    indiceA: indiceA,
    indiceB: indiceB,
    elementoA: array1[indiceA],
    elementoB: array2[indiceB]
  };
}

// Exemplo de uso
const array1 = [-1, 5];
const array2 = [26, 6];

const resultado = encontrarMenorDistancia(array1, array2);

console.log("Menor distância:", resultado.menorDistancia);
console.log("Índice no array 1:", resultado.indiceA);
console.log("Índice no array 2:", resultado.indiceB);
console.log("Elemento no array 1:", resultado.elementoA);
console.log("Elemento no array 2:", resultado.elementoB);

// Update header text
document.querySelector('#header').innerHTML = resultado.elementoA;

// Log to console
console.log(resultado)