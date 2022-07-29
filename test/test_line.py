#!python
# %%
import matplotlib.pyplot as plt
from numpy import array
from decomp_util import LineSegment2D, cal_vertices
import decomp_util
import sys
sys.path.append('../build')


ln_seg = array([array([-1.5, 0.0]), array([1.5, 0.3])])
obs = [array([-0.2, 1.5]),
       array([0, 1.5]),
       array([0, 1]),
       array([1, 0]),
       array([1.8, 0]),
       array([0.8, -1]),
       array([-0.5, -0.5]),
       array([-0.75, -0.5]),
       array([-1, -0.5]),
       array([-1, 0.8])]

decomp = LineSegment2D(ln_seg[0], ln_seg[1])
decomp.set_obs(obs)
decomp.set_local_bbox(array([2, 2]))
decomp.dilate(0)

elips = decomp.get_ellipsoid()

el_pts = array(elips.sample(40))

poly = decomp.get_polyhedron()
verts = array(cal_vertices(poly))

# %%

plt.figure()
plt.plot(ln_seg[:, 0], ln_seg[:, 1])
plt_obs = array(obs)
plt.scatter(plt_obs[:, 0], plt_obs[:, 1], c='black')
plt.plot(el_pts[:, 0], el_pts[:, 1])
plt.plot(verts[:, 0], verts[:, 1])
plt.grid(True)
plt.show()
# %%
