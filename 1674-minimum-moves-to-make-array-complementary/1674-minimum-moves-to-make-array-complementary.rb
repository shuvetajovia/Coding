# @param {Integer[]} nums
# @param {Integer} limit
# @return {Integer}
def min_moves(nums, limit)
    n = nums.length
    diff = Array.new(2 * limit + 2, 0)

    (0...(n / 2)).each do |i|
        a = nums[i]
        b = nums[n - 1 - i]

        low = [a, b].min + 1
        high = [a, b].max + limit
        sum = a + b

        # initially 2 moves
        diff[2] += 2

        # 1 move range
        diff[low] -= 1
        diff[high + 1] += 1

        # 0 move at exact sum
        diff[sum] -= 1
        diff[sum + 1] += 1
    end

    ans = Float::INFINITY
    cur = 0

    (2..2 * limit).each do |s|
        cur += diff[s]
        ans = [ans, cur].min
    end

    ans
end

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna