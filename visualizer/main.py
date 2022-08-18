import numpy as np
import plotly.graph_objects as go

wrong_data = np.loadtxt('../resources/points_wrong.txt')
good_data = np.loadtxt('../resources/points_good.txt')

xCoordPlane1 = np.array([0.5, 0.5, -0.5, 0.5])
yCoordPlane1 = np.array([-0.33, -0.33, -0.33, -0.33])
zCoordPlane1 = np.array([0.983, 0.2269, 0.2269, 0.983])

xCoordPlane2 = np.array([0.06159, 0.31881, 0.6643, 0.06159])
yCoordPlane2 = np.array([-0.6232, 0.43885, 0.3551, -0.6232])
zCoordPlane2 = np.array([0.9830, 0.9830, -0.2269, 0.9830])

plane1 = go.Scatter3d(x=xCoordPlane1, y=yCoordPlane1, z=zCoordPlane1)
plane2 = go.Scatter3d(x=xCoordPlane2, y=yCoordPlane2, z=zCoordPlane2)

w_marker_data = go.Scatter3d(
    x=wrong_data[:, 0],
    y=wrong_data[:, 1],
    z=wrong_data[:, 2],
    marker=go.scatter3d.Marker(size=1, color='red'),
    opacity=0.8,
    mode='markers'
)

g_marker_data = go.Scatter3d(
    x=good_data[:, 0],
    y=good_data[:, 1],
    z=good_data[:, 2],
    marker=go.scatter3d.Marker(size=1, color='green'),
    opacity=0.8,
    mode='markers'
)

fig = go.Figure(data=[
    plane1,
    plane2,
    w_marker_data,
    g_marker_data])
fig.show()
