**收获：**</br>
之前没有接触过罗马数字的计数，只是知道前面几个怎么写而已，通过这道题学习了一下。</br>
**罗马数字计数规则：**</br>
<pre><code>
罗马数字共有七个，即I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)。按照下面的规则可以表示任意正整数。</br>
重复数次：一个罗马数字重复几次，就表示这个数的几倍。</br>
右加左减：在一个较大的罗马数字的右边记上一个较小的罗马数字，表示大数字加小数字。在一个较大的数字的左边记上一个较小的罗马数字，表示大数字减小数字。</br>
但是，左减不能跨越等级。比如，99不可以用IC表示，用XCIX表示。</code></pre>