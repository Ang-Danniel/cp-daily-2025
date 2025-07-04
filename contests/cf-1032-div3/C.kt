import java.util.StringTokenizer
import java.io.PrintWriter
import kotlin.math.max
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }
@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

fun main(){
var t: Int = readInt()
while(t-- > 0) solve()
}

fun solve(){
    var n: Int = readInt()
    var m: Int = readInt()

    var ar = Array (n + 1) {IntArray(m + 1)}

    var maxx: Int = -1
    var inp: Int

    for (i in 1..n){
        for (j in 1..m){
            inp = readInt()       
            ar[i][j] = inp     
            maxx = max(inp, maxx)
        }
    }

    var rof: Int = -1
    var cof: Int = -1
    for (i in 1..n){
        var cnt: Int = 0
        for (j in 1..m){
            if (ar[i][j] == maxx) cnt++;
        }

        if (cnt >= 2) {
            if (rof != -1){
                println(maxx)
                return
            } else {
                rof = i
            }
        }
    }

    var allCnt: Int = 0

    for (j in 1..m) {
        var cnt: Int = 0
        for (i in 1..n) {
            if (ar[i][j] == maxx) {
                cnt++
                allCnt++
            }
        }
        if (cnt >= 2) {
            if (cof != -1) {
                println(maxx)
                return
            } else {
                cof = j
            }
        }
    }


    if(allCnt <= 2) {
        println(maxx - 1)
        return
    }

    if (allCnt > 2 && cof == -1 && rof == -1) {
        println(maxx)
        return
    }

    for (i in 1..n) { 
        for (j in 1..m) {
            if (ar[i][j] != maxx) continue

            if (i == rof || j == cof) continue

            if (cof != -1 && rof != -1) {
                println(maxx)
                return
            }

            if (rof == -1) rof = i
            if (cof == -1) cof = j
        }
    }

    println(maxx - 1)
}