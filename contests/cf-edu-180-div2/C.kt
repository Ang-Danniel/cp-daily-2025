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

fun solve(){
    var n: Int = readInt()
    var ar = readLine()!!.split(" ").map {it.toLong()}.toLongArray()
    
    ar.sort()

    var high: Long = ar[n-1]

    var ans: Long = 0
    var cons: Long

    for (i in 2..n-1) {
        for (j in i-1 downTo 1) {
            cons = max(high - (ar[i] + ar[j]), ar[i] - ar[j])
            // println("${i} ${j} ${ar[i]} ${ar[j]} ${cons}")

            var l: Int
            var r: Int
            var mid: Int
            l = 0
            r = j-1

            var save: Int = j

            while(l <= r){
                mid = (l + r) shr 1
                if (ar[mid] <= cons) {
                    l = mid + 1
                } else {
                    save = mid
                    r = mid - 1
                }
            }
            ans += j.toLong() - save.toLong()
            // println("Hasil: ${save} ${j-save}")
        }
    }
    println(ans)
}

fun main(){
    var t: Int = readInt();

    while (t-- > 0){
        solve()
    }
}