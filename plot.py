# import module
import matplotlib.pyplot as plt


def save_dots(x_list, y_list, y2_list=None, name='Test'):
    # set the title of a plot
    plt.title(name)

    # plot scatter plot with x and y data
    plt.scatter(x_list[:-2], y_list[:-1])
    if y2_list is not None:
        plt.scatter(x_list[:-2], y2_list[:-1])

    # plot with x and y data
    plt.plot(x_list[:-2], y_list[:-1], label=y_list[-1])
    if y2_list is not None:
        plt.plot(x_list[:-2], y2_list[:-1], label=y2_list[-1])

    plt.xlabel(x[-2])
    plt.ylabel(x[-1])
    plt.legend()

    plt.savefig('assets/' + name.lower() + '.png')


# initialize x and y coordinates
x = [512, 1024, 2048, 4096, 'Initial grid size', 'Execution time']
y = [0.697, 2.602, 9.696, 36.065, 'Serial']
y2 = [0.526, 2.447, 9.127, 34.180, 'Parallel']

save_dots(x, y, y2, 'Serial and Parallel Multi-grid comparison (with Jacobi solver)')
