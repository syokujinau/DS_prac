var a = [5, 3, 7, 1, 2, 6, 9]
printAry(a)
sort(a)
printAry(a)

function sort (A) {
  var t
  for (var i = 0; i < A.length; i++) {
    var f = false
    for (var j = 0; j < (A.length - 1) - i; j++) {
      if (A[j] > A[j + 1]) {
        t = A[j]
        A[j] = A[j + 1]
        A[j + 1] = t
      }
      f = true
    }

    if (!f) {
      return
    }
  }
}

/*
A[0 1 2 3 4]
*/
function printAry (A) {
  var str = ''
  for (var i = 0; i < A.length; i++) {
    str += (A[i] + ' ')
  }
  console.log(str)
}
