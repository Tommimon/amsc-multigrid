# import module
import matplotlib.pyplot as plt


def save_dots(x_list, y_list, name):
    # set the title of a plot
    plt.title(name)

    # plot scatter plot with x and y data
    plt.scatter(x, y)

    # plot with x and y data
    plt.plot(x, y)

    plt.savefig(name.lower() + '.png')


# initialize x and y coordinates
x = [0.1, 0.2, 0.3, 0.4, 0.5]
y = [6.2, -8.4, 8.5, 9.2, -6.3]

save_dots(x, y, "Test")
