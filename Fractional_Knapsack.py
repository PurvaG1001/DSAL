weights = [16, 22, 30]
profits = [45, 60, 80]
capacity = 40

# Calculate profit/weight ratio
ratio = [p/w for p, w in zip(profits, weights)]

# Combine items into tuples
items = list(zip(weights, profits, ratio))

# Define a function to return the ratio (third element)
def get_ratio(item):
    return item[2]


# Sort items by ratio descending using the function
items.sort(key=get_ratio, reverse=True)

total_profit = 0

print("Parcel\tWeight\tProfit\tFraction Taken")

for i, (w, p, r) in enumerate(items):

    if capacity >= w:
        fraction = 1
        capacity -= w
        total_profit += p

    else:
        fraction = capacity / w
        total_profit += p * fraction
        capacity = 0

    print(f"{i+1}\t{w}\t{p}\t{fraction:.2f}")

    if capacity == 0:
        break

print(f"\nTotal Profit: {total_profit:.2f}")
