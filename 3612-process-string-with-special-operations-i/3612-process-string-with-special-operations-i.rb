# @param {String} s
# @return {String}
def process_str(s)
    result = ""

    s.each_char do |ch|
        if ('a'..'z').include?(ch)
            result << ch
        elsif ch == '*'
            result.chop! unless result.empty?
        elsif ch == '#'
            result += result
        elsif ch == '%'
            result.reverse!
        end
    end

    result
end

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna