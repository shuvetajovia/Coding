# @param {String[]} words
# @param {Integer[]} weights
# @return {String}
def map_word_weights(words, weights)
    result = ""

    words.each do |word|
        sum = 0

        word.each_char do |ch|
            sum += weights[ch.ord - 'a'.ord]
        end

        mod = sum % 26
        result += (122 - mod).chr
    end

    result
end

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna