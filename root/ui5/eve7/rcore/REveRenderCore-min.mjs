var _points = [ new Vector3(), new Vector3(), new Vector3(), new Vector3(), new Vector3(), new Vector3(), new Vector3(), new Vector3() ], _vector$5 = new Vector3(), _v0$1 = new Vector3(), _v1$2 = new Vector3(), _v2$1 = new Vector3(), _f0 = new Vector3(), _f1 = new Vector3(), _f2 = new Vector3(), _center = new Vector3(), _extents = new Vector3(), _triangleNormal = new Vector3(), _testAxis = new Vector3();

function Box3(t, e) {
 this.min = void 0 !== t ? t : new Vector3(1 / 0, 1 / 0, 1 / 0), this.max = void 0 !== e ? e : new Vector3(-1 / 0, -1 / 0, -1 / 0);
}

function satForAxes(t, e, i, r, s) {
 for (var a = 0, n = t.length - 3; a <= n; a += 3) {
  _testAxis.fromArray(t, a);
  var o = s.x * Math.abs(_testAxis.x) + s.y * Math.abs(_testAxis.y) + s.z * Math.abs(_testAxis.z), h = e.dot(_testAxis), u = i.dot(_testAxis), l = r.dot(_testAxis);
  if (Math.max(-Math.max(h, u, l), Math.min(h, u, l)) > o) return !1;
 }
 return !0;
}

Object.assign(Box3.prototype, {
 isBox3: !0,
 set: function(t, e) {
  return this.min.copy(t), this.max.copy(e), this;
 },
 setFromArray: function(t) {
  for (var e = 1 / 0, i = 1 / 0, r = 1 / 0, s = -1 / 0, a = -1 / 0, n = -1 / 0, o = 0, h = t.length; o < h; o += 3) {
   var u = t[o], l = t[o + 1], _ = t[o + 2];
   u < e && (e = u), l < i && (i = l), _ < r && (r = _), s < u && (s = u), a < l && (a = l), 
   n < _ && (n = _);
  }
  return this.min.set(e, i, r), this.max.set(s, a, n), this;
 },
 setFromBufferAttribute: function(t) {
  for (var e = 1 / 0, i = 1 / 0, r = 1 / 0, s = -1 / 0, a = -1 / 0, n = -1 / 0, o = 0, h = t.count; o < h; o++) {
   var u = t.getX(o), l = t.getY(o), _ = t.getZ(o);
   u < e && (e = u), l < i && (i = l), _ < r && (r = _), s < u && (s = u), a < l && (a = l), 
   n < _ && (n = _);
  }
  return this.min.set(e, i, r), this.max.set(s, a, n), this;
 },
 setFromPoints: function(t) {
  this.makeEmpty();
  for (var e = 0, i = t.length; e < i; e++) this.expandByPoint(t[e]);
  return this;
 },
 setFromCenterAndSize: function(t, e) {
  e = _vector$5.copy(e).multiplyScalar(.5);
  return this.min.copy(t).sub(e), this.max.copy(t).add(e), this;
 },
 setFromObject: function(t) {
  return this.makeEmpty(), this.expandByObject(t);
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.min.copy(t.min), this.max.copy(t.max), this;
 },
 makeEmpty: function() {
  return this.min.x = this.min.y = this.min.z = 1 / 0, this.max.x = this.max.y = this.max.z = -1 / 0, 
  this;
 },
 isEmpty: function() {
  return this.max.x < this.min.x || this.max.y < this.min.y || this.max.z < this.min.z;
 },
 getCenter: function(t) {
  return void 0 === t && (console.warn("Box3: .getCenter() target is now required"), 
  t = new Vector3()), this.isEmpty() ? t.set(0, 0, 0) : t.addVectors(this.min, this.max).multiplyScalar(.5);
 },
 getSize: function(t) {
  return void 0 === t && (console.warn("Box3: .getSize() target is now required"), 
  t = new Vector3()), this.isEmpty() ? t.set(0, 0, 0) : t.subVectors(this.max, this.min);
 },
 expandByPoint: function(t) {
  return this.min.min(t), this.max.max(t), this;
 },
 expandByVector: function(t) {
  return this.min.sub(t), this.max.add(t), this;
 },
 expandByScalar: function(t) {
  return this.min.addScalar(-t), this.max.addScalar(t), this;
 },
 expandByObject: function(e) {
  e.updateWorldMatrix(!1, !1);
  var t = e.geometry;
  if (void 0 !== t) {
   var i = t.vertices;
   for (let t = 0; t < i.array.length; t += i.itemSize) _vector$5.set(i.array[t], i.array[t + 1], i.array[t + 2]), 
   _vector$5.applyMatrix4(e.matrixWorld), this.expandByPoint(_vector$5);
  }
  for (var r = e.children, s = 0, a = r.length; s < a; s++) this.expandByObject(r[s]);
  return this;
 },
 containsPoint: function(t) {
  return !(t.x < this.min.x || t.x > this.max.x || t.y < this.min.y || t.y > this.max.y || t.z < this.min.z || t.z > this.max.z);
 },
 containsBox: function(t) {
  return this.min.x <= t.min.x && t.max.x <= this.max.x && this.min.y <= t.min.y && t.max.y <= this.max.y && this.min.z <= t.min.z && t.max.z <= this.max.z;
 },
 getParameter: function(t, e) {
  return void 0 === e && (console.warn("Box3: .getParameter() target is now required"), 
  e = new Vector3()), e.set((t.x - this.min.x) / (this.max.x - this.min.x), (t.y - this.min.y) / (this.max.y - this.min.y), (t.z - this.min.z) / (this.max.z - this.min.z));
 },
 intersectsBox: function(t) {
  return !(t.max.x < this.min.x || t.min.x > this.max.x || t.max.y < this.min.y || t.min.y > this.max.y || t.max.z < this.min.z || t.min.z > this.max.z);
 },
 intersectsSphere: function(t) {
  return this.clampPoint(t.center, _vector$5), _vector$5.distanceToSquared(t.center) <= t.radius * t.radius;
 },
 intersectsPlane: function(t) {
  var e, i = 0 < t.normal.x ? (e = t.normal.x * this.min.x, t.normal.x * this.max.x) : (e = t.normal.x * this.max.x, 
  t.normal.x * this.min.x);
  return 0 < t.normal.y ? (e += t.normal.y * this.min.y, i += t.normal.y * this.max.y) : (e += t.normal.y * this.max.y, 
  i += t.normal.y * this.min.y), 0 < t.normal.z ? (e += t.normal.z * this.min.z, 
  i += t.normal.z * this.max.z) : (e += t.normal.z * this.max.z, i += t.normal.z * this.min.z), 
  e <= -t.constant && i >= -t.constant;
 },
 intersectsTriangle: function(t) {
  return !this.isEmpty() && (this.getCenter(_center), _extents.subVectors(this.max, _center), 
  _v0$1.subVectors(t.a, _center), _v1$2.subVectors(t.b, _center), _v2$1.subVectors(t.c, _center), 
  _f0.subVectors(_v1$2, _v0$1), _f1.subVectors(_v2$1, _v1$2), _f2.subVectors(_v0$1, _v2$1), 
  !!satForAxes([ 0, -_f0.z, _f0.y, 0, -_f1.z, _f1.y, 0, -_f2.z, _f2.y, _f0.z, 0, -_f0.x, _f1.z, 0, -_f1.x, _f2.z, 0, -_f2.x, -_f0.y, _f0.x, 0, -_f1.y, _f1.x, 0, -_f2.y, _f2.x, 0 ], _v0$1, _v1$2, _v2$1, _extents)) && !!satForAxes([ 1, 0, 0, 0, 1, 0, 0, 0, 1 ], _v0$1, _v1$2, _v2$1, _extents) && (_triangleNormal.crossVectors(_f0, _f1), 
  satForAxes([ _triangleNormal.x, _triangleNormal.y, _triangleNormal.z ], _v0$1, _v1$2, _v2$1, _extents));
 },
 clampPoint: function(t, e) {
  return void 0 === e && (console.warn("Box3: .clampPoint() target is now required"), 
  e = new Vector3()), e.copy(t).clamp(this.min, this.max);
 },
 distanceToPoint: function(t) {
  return _vector$5.copy(t).clamp(this.min, this.max).sub(t).length();
 },
 getBoundingSphere: function(t) {
  return void 0 === t && console.error("Box3: .getBoundingSphere() target is now required"), 
  this.getCenter(t.center), t.radius = .5 * this.getSize(_vector$5).length(), t;
 },
 intersect: function(t) {
  return this.min.max(t.min), this.max.min(t.max), this.isEmpty() && this.makeEmpty(), 
  this;
 },
 union: function(t) {
  return this.min.min(t.min), this.max.max(t.max), this;
 },
 applyMatrix4: function(t) {
  return this.isEmpty() || (_points[0].set(this.min.x, this.min.y, this.min.z).applyMatrix4(t), 
  _points[1].set(this.min.x, this.min.y, this.max.z).applyMatrix4(t), _points[2].set(this.min.x, this.max.y, this.min.z).applyMatrix4(t), 
  _points[3].set(this.min.x, this.max.y, this.max.z).applyMatrix4(t), _points[4].set(this.max.x, this.min.y, this.min.z).applyMatrix4(t), 
  _points[5].set(this.max.x, this.min.y, this.max.z).applyMatrix4(t), _points[6].set(this.max.x, this.max.y, this.min.z).applyMatrix4(t), 
  _points[7].set(this.max.x, this.max.y, this.max.z).applyMatrix4(t), this.setFromPoints(_points)), 
  this;
 },
 translate: function(t) {
  return this.min.add(t), this.max.add(t), this;
 },
 equals: function(t) {
  return t.min.equals(this.min) && t.max.equals(this.max);
 },
 center: function(t) {
  return (t || new Vector3()).addVectors(this.min, this.max).multiplyScalar(.5);
 }
});

var _box = new Box3();

function Sphere(t, e) {
 this.center = void 0 !== t ? t : new Vector3(), this.radius = void 0 !== e ? e : 0;
}

Object.assign(Sphere.prototype, {
 set: function(t, e) {
  return this.center.copy(t), this.radius = e, this;
 },
 setFromPoints: function(t, e) {
  for (var i = this.center, r = (void 0 !== e ? i.copy(e) : _box.setFromPoints(t).getCenter(i), 
  0), s = 0, a = t.length; s < a; s++) r = Math.max(r, i.distanceToSquared(t[s]));
  return this.radius = Math.sqrt(r), this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.center.copy(t.center), this.radius = t.radius, this;
 },
 empty: function() {
  return this.radius <= 0;
 },
 containsPoint: function(t) {
  return t.distanceToSquared(this.center) <= this.radius * this.radius;
 },
 distanceToPoint: function(t) {
  return t.distanceTo(this.center) - this.radius;
 },
 intersectsSphere: function(t) {
  var e = this.radius + t.radius;
  return t.center.distanceToSquared(this.center) <= e * e;
 },
 intersectsBox: function(t) {
  return t.intersectsSphere(this);
 },
 intersectsPlane: function(t) {
  return Math.abs(t.distanceToPoint(this.center)) <= this.radius;
 },
 clampPoint: function(t, e) {
  var i = this.center.distanceToSquared(t);
  return void 0 === e && (console.warn("Sphere: .clampPoint() target is now required"), 
  e = new Vector3()), e.copy(t), i > this.radius * this.radius && (e.sub(this.center).normalize(), 
  e.multiplyScalar(this.radius).add(this.center)), e;
 },
 getBoundingBox: function(t) {
  return void 0 === t && (console.warn("Sphere: .getBoundingBox() target is now required"), 
  t = new Box3()), t.set(this.center, this.center), t.expandByScalar(this.radius), 
  t;
 },
 applyMatrix4: function(t) {
  return this.center.applyMatrix4(t), this.radius = this.radius * t.getMaxScaleOnAxis(), 
  this;
 },
 translate: function(t) {
  return this.center.add(t), this;
 },
 equals: function(t) {
  return t.center.equals(this.center) && t.radius === this.radius;
 }
});

for (var _lut = [], i$1 = 0; i$1 < 256; i$1++) _lut[i$1] = (i$1 < 16 ? "0" : "") + i$1.toString(16);

var _Math = {
 DEG2RAD: Math.PI / 180,
 RAD2DEG: 180 / Math.PI,
 generateUUID: function() {
  var t = 4294967295 * Math.random() | 0, e = 4294967295 * Math.random() | 0, i = 4294967295 * Math.random() | 0, r = 4294967295 * Math.random() | 0;
  return (_lut[255 & t] + _lut[t >> 8 & 255] + _lut[t >> 16 & 255] + _lut[t >> 24 & 255] + "-" + _lut[255 & e] + _lut[e >> 8 & 255] + "-" + _lut[e >> 16 & 15 | 64] + _lut[e >> 24 & 255] + "-" + _lut[63 & i | 128] + _lut[i >> 8 & 255] + "-" + _lut[i >> 16 & 255] + _lut[i >> 24 & 255] + _lut[255 & r] + _lut[r >> 8 & 255] + _lut[r >> 16 & 255] + _lut[r >> 24 & 255]).toUpperCase();
 },
 clamp: function(t, e, i) {
  return Math.max(e, Math.min(i, t));
 },
 euclideanModulo: function(t, e) {
  return (t % e + e) % e;
 },
 mapLinear: function(t, e, i, r, s) {
  return r + (t - e) * (s - r) / (i - e);
 },
 lerp: function(t, e, i) {
  return (1 - i) * t + i * e;
 },
 smoothstep: function(t, e, i) {
  return t <= e ? 0 : i <= t ? 1 : (t = (t - e) / (i - e)) * t * (3 - 2 * t);
 },
 smootherstep: function(t, e, i) {
  return t <= e ? 0 : i <= t ? 1 : (t = (t - e) / (i - e)) * t * t * (t * (6 * t - 15) + 10);
 },
 randInt: function(t, e) {
  return t + Math.floor(Math.random() * (e - t + 1));
 },
 randFloat: function(t, e) {
  return t + Math.random() * (e - t);
 },
 randFloatSpread: function(t) {
  return t * (.5 - Math.random());
 },
 degToRad: function(t) {
  return t * _Math.DEG2RAD;
 },
 radToDeg: function(t) {
  return t * _Math.RAD2DEG;
 },
 isPowerOfTwo: function(t) {
  return 0 == (t & t - 1) && 0 !== t;
 },
 ceilPowerOfTwo: function(t) {
  return Math.pow(2, Math.ceil(Math.log(t) / Math.LN2));
 },
 floorPowerOfTwo: function(t) {
  return Math.pow(2, Math.floor(Math.log(t) / Math.LN2));
 },
 computeSpheresBoundingSphere: function(e) {
  var i = [];
  for (let t = 0; t < e.length; t++) {
   var r = e[t].getBoundingBox(), s = r.min, a = r.max, n = e[t].center;
   for (let t = 0; t < 3; t++) i.push(...n.toArray()), i[i.length - (3 - t)] = s.getComponent(t), 
   i.push(...n.toArray()), i[i.length - (3 - t)] = a.getComponent(t);
  }
  var t = new Box3(), o = new Sphere(), h = new Vector3();
  t.setFromArray(i), t.center(o.center);
  let u = 0;
  for (let t = 0; t < i.length; t += 3) h.fromArray(i, t), u = Math.max(u, o.center.distanceToSquared(h));
  return o.radius = Math.sqrt(u), isNaN(o.radius) && console.error("Geometry error: Bounding sphere radius is NaN."), 
  o;
 }
};

function Quaternion(t, e, i, r) {
 this._x = t || 0, this._y = e || 0, this._z = i || 0, this._w = void 0 !== r ? r : 1;
}

Object.assign(Quaternion, {
 slerp: function(t, e, i, r) {
  return i.copy(t).slerp(e, r);
 },
 slerpFlat: function(t, e, i, r, s, a, n) {
  var o, h, u, l = i[r + 0], _ = i[r + 1], c = i[r + 2], i = i[r + 3], r = s[a + 0], d = s[a + 1], m = s[a + 2], s = s[a + 3];
  i === s && l === r && _ === d && c === m || (a = 1 - n, o = 0 <= (h = l * r + _ * d + c * m + i * s) ? 1 : -1, 
  (u = 1 - h * h) > Number.EPSILON && (u = Math.sqrt(u), h = Math.atan2(u, h * o), 
  a = Math.sin(a * h) / u, n = Math.sin(n * h) / u), l = l * a + r * (h = n * o), 
  _ = _ * a + d * h, c = c * a + m * h, i = i * a + s * h, a === 1 - n && (l *= u = 1 / Math.sqrt(l * l + _ * _ + c * c + i * i), 
  _ *= u, c *= u, i *= u)), t[e] = l, t[e + 1] = _, t[e + 2] = c, t[e + 3] = i;
 }
}), Object.defineProperties(Quaternion.prototype, {
 x: {
  get: function() {
   return this._x;
  },
  set: function(t) {
   this._x = t, this._onChangeCallback();
  }
 },
 y: {
  get: function() {
   return this._y;
  },
  set: function(t) {
   this._y = t, this._onChangeCallback();
  }
 },
 z: {
  get: function() {
   return this._z;
  },
  set: function(t) {
   this._z = t, this._onChangeCallback();
  }
 },
 w: {
  get: function() {
   return this._w;
  },
  set: function(t) {
   this._w = t, this._onChangeCallback();
  }
 }
}), Object.assign(Quaternion.prototype, {
 isQuaternion: !0,
 set: function(t, e, i, r) {
  return this._x = t, this._y = e, this._z = i, this._w = r, this._onChangeCallback(), 
  this;
 },
 clone: function() {
  return new this.constructor(this._x, this._y, this._z, this._w);
 },
 copy: function(t) {
  return this._x = t.x, this._y = t.y, this._z = t.z, this._w = t.w, this._onChangeCallback(), 
  this;
 },
 setFromEuler: function(t, e) {
  var i, r, s, a, n, o, h;
  if (t && t.isEuler) return n = t._x, o = t._y, i = t._z, t = t.order, a = Math.cos, 
  h = Math.sin, r = a(n / 2), s = a(o / 2), a = a(i / 2), n = h(n / 2), o = h(o / 2), 
  h = h(i / 2), "XYZ" === t ? (this._x = n * s * a + r * o * h, this._y = r * o * a - n * s * h, 
  this._z = r * s * h + n * o * a, this._w = r * s * a - n * o * h) : "YXZ" === t ? (this._x = n * s * a + r * o * h, 
  this._y = r * o * a - n * s * h, this._z = r * s * h - n * o * a, this._w = r * s * a + n * o * h) : "ZXY" === t ? (this._x = n * s * a - r * o * h, 
  this._y = r * o * a + n * s * h, this._z = r * s * h + n * o * a, this._w = r * s * a - n * o * h) : "ZYX" === t ? (this._x = n * s * a - r * o * h, 
  this._y = r * o * a + n * s * h, this._z = r * s * h - n * o * a, this._w = r * s * a + n * o * h) : "YZX" === t ? (this._x = n * s * a + r * o * h, 
  this._y = r * o * a + n * s * h, this._z = r * s * h - n * o * a, this._w = r * s * a - n * o * h) : "XZY" === t && (this._x = n * s * a - r * o * h, 
  this._y = r * o * a - n * s * h, this._z = r * s * h + n * o * a, this._w = r * s * a + n * o * h), 
  !1 !== e && this._onChangeCallback(), this;
  throw new Error("Quaternion: .setFromEuler() now expects an Euler rotation rather than a Vector3 and order.");
 },
 setFromAxisAngle: function(t, e) {
  var e = e / 2, i = Math.sin(e);
  return this._x = t.x * i, this._y = t.y * i, this._z = t.z * i, this._w = Math.cos(e), 
  this._onChangeCallback(), this;
 },
 setFromRotationMatrix: function(t) {
  var e, t = t.elements, i = t[0], r = t[4], s = t[8], a = t[1], n = t[5], o = t[9], h = t[2], u = t[6], t = t[10], l = i + n + t;
  return 0 < l ? (e = .5 / Math.sqrt(l + 1), this._w = .25 / e, this._x = (u - o) * e, 
  this._y = (s - h) * e, this._z = (a - r) * e) : n < i && t < i ? (e = 2 * Math.sqrt(1 + i - n - t), 
  this._w = (u - o) / e, this._x = .25 * e, this._y = (r + a) / e, this._z = (s + h) / e) : t < n ? (e = 2 * Math.sqrt(1 + n - i - t), 
  this._w = (s - h) / e, this._x = (r + a) / e, this._y = .25 * e, this._z = (o + u) / e) : (e = 2 * Math.sqrt(1 + t - i - n), 
  this._w = (a - r) / e, this._x = (s + h) / e, this._y = (o + u) / e, this._z = .25 * e), 
  this._onChangeCallback(), this;
 },
 setFromUnitVectors: function(t, e) {
  var i = t.dot(e) + 1;
  return i < 1e-6 ? (i = 0, Math.abs(t.x) > Math.abs(t.z) ? (this._x = -t.y, this._y = t.x, 
  this._z = 0) : (this._x = 0, this._y = -t.z, this._z = t.y)) : (this._x = t.y * e.z - t.z * e.y, 
  this._y = t.z * e.x - t.x * e.z, this._z = t.x * e.y - t.y * e.x), this._w = i, 
  this.normalize();
 },
 angleTo: function(t) {
  return 2 * Math.acos(Math.abs(_Math.clamp(this.dot(t), -1, 1)));
 },
 rotateTowards: function(t, e) {
  var i = this.angleTo(t);
  return 0 !== i && (e = Math.min(1, e / i), this.slerp(t, e)), this;
 },
 inverse: function() {
  return this.conjugate();
 },
 conjugate: function() {
  return this._x *= -1, this._y *= -1, this._z *= -1, this._onChangeCallback(), 
  this;
 },
 dot: function(t) {
  return this._x * t._x + this._y * t._y + this._z * t._z + this._w * t._w;
 },
 lengthSq: function() {
  return this._x * this._x + this._y * this._y + this._z * this._z + this._w * this._w;
 },
 length: function() {
  return Math.sqrt(this._x * this._x + this._y * this._y + this._z * this._z + this._w * this._w);
 },
 normalize: function() {
  var t = this.length();
  return 0 === t ? (this._x = 0, this._y = 0, this._z = 0, this._w = 1) : (this._x = this._x * (t = 1 / t), 
  this._y = this._y * t, this._z = this._z * t, this._w = this._w * t), this._onChangeCallback(), 
  this;
 },
 multiply: function(t, e) {
  return void 0 !== e ? (console.warn("Quaternion: .multiply() now only accepts one argument. Use .multiplyQuaternions( a, b ) instead."), 
  this.multiplyQuaternions(t, e)) : this.multiplyQuaternions(this, t);
 },
 premultiply: function(t) {
  return this.multiplyQuaternions(t, this);
 },
 multiplyQuaternions: function(t, e) {
  var i = t._x, r = t._y, s = t._z, t = t._w, a = e._x, n = e._y, o = e._z, e = e._w;
  return this._x = i * e + t * a + r * o - s * n, this._y = r * e + t * n + s * a - i * o, 
  this._z = s * e + t * o + i * n - r * a, this._w = t * e - i * a - r * n - s * o, 
  this._onChangeCallback(), this;
 },
 slerp: function(t, e) {
  if (0 !== e) {
   if (1 === e) return this.copy(t);
   var i, r = this._x, s = this._y, a = this._z, n = this._w, o = n * t._w + r * t._x + s * t._y + a * t._z;
   o < 0 ? (this._w = -t._w, this._x = -t._x, this._y = -t._y, this._z = -t._z, 
   o = -o) : this.copy(t), 1 <= o ? (this._w = n, this._x = r, this._y = s, this._z = a) : ((t = 1 - o * o) <= Number.EPSILON ? (this._w = (i = 1 - e) * n + e * this._w, 
   this._x = i * r + e * this._x, this._y = i * s + e * this._y, this._z = i * a + e * this._z, 
   this.normalize()) : (i = Math.sqrt(t), t = Math.atan2(i, o), o = Math.sin((1 - e) * t) / i, 
   e = Math.sin(e * t) / i, this._w = n * o + this._w * e, this._x = r * o + this._x * e, 
   this._y = s * o + this._y * e, this._z = a * o + this._z * e), this._onChangeCallback());
  }
  return this;
 },
 equals: function(t) {
  return t._x === this._x && t._y === this._y && t._z === this._z && t._w === this._w;
 },
 fromArray: function(t, e) {
  return this._x = t[e = void 0 === e ? 0 : e], this._y = t[e + 1], this._z = t[e + 2], 
  this._w = t[e + 3], this._onChangeCallback(), this;
 },
 toArray: function(t, e) {
  return (t = void 0 === t ? [] : t)[e = void 0 === e ? 0 : e] = this._x, t[e + 1] = this._y, 
  t[e + 2] = this._z, t[e + 3] = this._w, t;
 },
 _onChange: function(t) {
  return this._onChangeCallback = t, this;
 },
 _onChangeCallback: function() {}
});

var _vector$4 = new Vector3(), _quaternion$1 = new Quaternion();

function Vector3(t, e, i) {
 this.x = t || 0, this.y = e || 0, this.z = i || 0;
}

Object.assign(Vector3.prototype, {
 isVector3: !0,
 set: function(t, e, i) {
  return this.x = t, this.y = e, this.z = i, this;
 },
 setScalar: function(t) {
  return this.x = t, this.y = t, this.z = t, this;
 },
 setX: function(t) {
  return this.x = t, this;
 },
 setY: function(t) {
  return this.y = t, this;
 },
 setZ: function(t) {
  return this.z = t, this;
 },
 setComponent: function(t, e) {
  switch (t) {
  case 0:
   this.x = e;
   break;

  case 1:
   this.y = e;
   break;

  case 2:
   this.z = e;
   break;

  default:
   throw new Error("index is out of range: " + t);
  }
  return this;
 },
 getComponent: function(t) {
  switch (t) {
  case 0:
   return this.x;

  case 1:
   return this.y;

  case 2:
   return this.z;

  default:
   throw new Error("index is out of range: " + t);
  }
 },
 clone: function() {
  return new this.constructor(this.x, this.y, this.z);
 },
 copy: function(t) {
  return this.x = t.x, this.y = t.y, this.z = t.z, this;
 },
 add: function(t, e) {
  return void 0 !== e ? (console.warn("Vector3: .add() now only accepts one argument. Use .addVectors( a, b ) instead."), 
  this.addVectors(t, e)) : (this.x += t.x, this.y += t.y, this.z += t.z, this);
 },
 addScalar: function(t) {
  return this.x += t, this.y += t, this.z += t, this;
 },
 addVectors: function(t, e) {
  return this.x = t.x + e.x, this.y = t.y + e.y, this.z = t.z + e.z, this;
 },
 addScaledVector: function(t, e) {
  return this.x += t.x * e, this.y += t.y * e, this.z += t.z * e, this;
 },
 sub: function(t, e) {
  return void 0 !== e ? (console.warn("Vector3: .sub() now only accepts one argument. Use .subVectors( a, b ) instead."), 
  this.subVectors(t, e)) : (this.x -= t.x, this.y -= t.y, this.z -= t.z, this);
 },
 subScalar: function(t) {
  return this.x -= t, this.y -= t, this.z -= t, this;
 },
 subVectors: function(t, e) {
  return this.x = t.x - e.x, this.y = t.y - e.y, this.z = t.z - e.z, this;
 },
 multiply: function(t, e) {
  return void 0 !== e ? (console.warn("Vector3: .multiply() now only accepts one argument. Use .multiplyVectors( a, b ) instead."), 
  this.multiplyVectors(t, e)) : (this.x *= t.x, this.y *= t.y, this.z *= t.z, this);
 },
 multiplyScalar: function(t) {
  return this.x *= t, this.y *= t, this.z *= t, this;
 },
 multiplyVectors: function(t, e) {
  return this.x = t.x * e.x, this.y = t.y * e.y, this.z = t.z * e.z, this;
 },
 applyEuler: function(t) {
  return t && t.isEuler || console.error("Vector3: .applyEuler() now expects an Euler rotation rather than a Vector3 and order."), 
  this.applyQuaternion(_quaternion$1.setFromEuler(t));
 },
 applyAxisAngle: function(t, e) {
  return this.applyQuaternion(_quaternion$1.setFromAxisAngle(t, e));
 },
 applyMatrix3: function(t) {
  var e = this.x, i = this.y, r = this.z, t = t.elements;
  return this.x = t[0] * e + t[3] * i + t[6] * r, this.y = t[1] * e + t[4] * i + t[7] * r, 
  this.z = t[2] * e + t[5] * i + t[8] * r, this;
 },
 applyMatrix4: function(t) {
  var e = this.x, i = this.y, r = this.z, t = t.elements, s = 1 / (t[3] * e + t[7] * i + t[11] * r + t[15]);
  return this.x = (t[0] * e + t[4] * i + t[8] * r + t[12]) * s, this.y = (t[1] * e + t[5] * i + t[9] * r + t[13]) * s, 
  this.z = (t[2] * e + t[6] * i + t[10] * r + t[14]) * s, this;
 },
 applyQuaternion: function(t) {
  var e = this.x, i = this.y, r = this.z, s = t.x, a = t.y, n = t.z, t = t.w, o = t * e + a * r - n * i, h = t * i + n * e - s * r, u = t * r + s * i - a * e, e = -s * e - a * i - n * r;
  return this.x = o * t + e * -s + h * -n - u * -a, this.y = h * t + e * -a + u * -s - o * -n, 
  this.z = u * t + e * -n + o * -a - h * -s, this;
 },
 project: function(t) {
  return this.applyMatrix4(t.matrixWorldInverse).applyMatrix4(t.projectionMatrix);
 },
 unproject: function(t) {
  return this.applyMatrix4(t.projectionMatrixInverse).applyMatrix4(t.matrixWorld);
 },
 transformDirection: function(t) {
  var e = this.x, i = this.y, r = this.z, t = t.elements;
  return this.x = t[0] * e + t[4] * i + t[8] * r, this.y = t[1] * e + t[5] * i + t[9] * r, 
  this.z = t[2] * e + t[6] * i + t[10] * r, this.normalize();
 },
 divide: function(t) {
  return this.x /= t.x, this.y /= t.y, this.z /= t.z, this;
 },
 divideScalar: function(t) {
  return this.multiplyScalar(1 / t);
 },
 min: function(t) {
  return this.x = Math.min(this.x, t.x), this.y = Math.min(this.y, t.y), this.z = Math.min(this.z, t.z), 
  this;
 },
 max: function(t) {
  return this.x = Math.max(this.x, t.x), this.y = Math.max(this.y, t.y), this.z = Math.max(this.z, t.z), 
  this;
 },
 clamp: function(t, e) {
  return this.x = Math.max(t.x, Math.min(e.x, this.x)), this.y = Math.max(t.y, Math.min(e.y, this.y)), 
  this.z = Math.max(t.z, Math.min(e.z, this.z)), this;
 },
 clampScalar: function(t, e) {
  return this.x = Math.max(t, Math.min(e, this.x)), this.y = Math.max(t, Math.min(e, this.y)), 
  this.z = Math.max(t, Math.min(e, this.z)), this;
 },
 clampLength: function(t, e) {
  var i = this.length();
  return this.divideScalar(i || 1).multiplyScalar(Math.max(t, Math.min(e, i)));
 },
 floor: function() {
  return this.x = Math.floor(this.x), this.y = Math.floor(this.y), this.z = Math.floor(this.z), 
  this;
 },
 ceil: function() {
  return this.x = Math.ceil(this.x), this.y = Math.ceil(this.y), this.z = Math.ceil(this.z), 
  this;
 },
 round: function() {
  return this.x = Math.round(this.x), this.y = Math.round(this.y), this.z = Math.round(this.z), 
  this;
 },
 roundToZero: function() {
  return this.x = this.x < 0 ? Math.ceil(this.x) : Math.floor(this.x), this.y = this.y < 0 ? Math.ceil(this.y) : Math.floor(this.y), 
  this.z = this.z < 0 ? Math.ceil(this.z) : Math.floor(this.z), this;
 },
 negate: function() {
  return this.x = -this.x, this.y = -this.y, this.z = -this.z, this;
 },
 dot: function(t) {
  return this.x * t.x + this.y * t.y + this.z * t.z;
 },
 lengthSq: function() {
  return this.x * this.x + this.y * this.y + this.z * this.z;
 },
 length: function() {
  return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
 },
 manhattanLength: function() {
  return Math.abs(this.x) + Math.abs(this.y) + Math.abs(this.z);
 },
 normalize: function() {
  return this.divideScalar(this.length() || 1);
 },
 setLength: function(t) {
  return this.normalize().multiplyScalar(t);
 },
 lerp: function(t, e) {
  return this.x += (t.x - this.x) * e, this.y += (t.y - this.y) * e, this.z += (t.z - this.z) * e, 
  this;
 },
 lerpVectors: function(t, e, i) {
  return this.subVectors(e, t).multiplyScalar(i).add(t);
 },
 cross: function(t, e) {
  return void 0 !== e ? (console.warn("Vector3: .cross() now only accepts one argument. Use .crossVectors( a, b ) instead."), 
  this.crossVectors(t, e)) : this.crossVectors(this, t);
 },
 crossVectors: function(t, e) {
  var i = t.x, r = t.y, t = t.z, s = e.x, a = e.y, e = e.z;
  return this.x = r * e - t * a, this.y = t * s - i * e, this.z = i * a - r * s, 
  this;
 },
 projectOnVector: function(t) {
  var e = t.dot(this) / t.lengthSq();
  return this.copy(t).multiplyScalar(e);
 },
 projectOnPlane: function(t) {
  return _vector$4.copy(this).projectOnVector(t), this.sub(_vector$4);
 },
 reflect: function(t) {
  return this.sub(_vector$4.copy(t).multiplyScalar(2 * this.dot(t)));
 },
 angleTo: function(t) {
  var e = Math.sqrt(this.lengthSq() * t.lengthSq()), t = (0 === e && console.error("Vector3: angleTo() can't handle zero length vectors."), 
  this.dot(t) / e);
  return Math.acos(_Math.clamp(t, -1, 1));
 },
 distanceTo: function(t) {
  return Math.sqrt(this.distanceToSquared(t));
 },
 distanceToSquared: function(t) {
  var e = this.x - t.x, i = this.y - t.y, t = this.z - t.z;
  return e * e + i * i + t * t;
 },
 manhattanDistanceTo: function(t) {
  return Math.abs(this.x - t.x) + Math.abs(this.y - t.y) + Math.abs(this.z - t.z);
 },
 setFromSpherical: function(t) {
  return this.setFromSphericalCoords(t.radius, t.phi, t.theta);
 },
 setFromSphericalCoords: function(t, e, i) {
  var r = Math.sin(e) * t;
  return this.x = r * Math.sin(i), this.y = Math.cos(e) * t, this.z = r * Math.cos(i), 
  this;
 },
 setFromCylindrical: function(t) {
  return this.setFromCylindricalCoords(t.radius, t.theta, t.y);
 },
 setFromCylindricalCoords: function(t, e, i) {
  return this.x = t * Math.sin(e), this.y = i, this.z = t * Math.cos(e), this;
 },
 setFromMatrixPosition: function(t) {
  t = t.elements;
  return this.x = t[12], this.y = t[13], this.z = t[14], this;
 },
 setFromMatrixScale: function(t) {
  var e = this.setFromMatrixColumn(t, 0).length(), i = this.setFromMatrixColumn(t, 1).length(), t = this.setFromMatrixColumn(t, 2).length();
  return this.x = e, this.y = i, this.z = t, this;
 },
 setFromMatrixColumn: function(t, e) {
  return this.fromArray(t.elements, 4 * e);
 },
 equals: function(t) {
  return t.x === this.x && t.y === this.y && t.z === this.z;
 },
 fromArray: function(t, e) {
  return this.x = t[e = void 0 === e ? 0 : e], this.y = t[e + 1], this.z = t[e + 2], 
  this;
 },
 toArray: function(t, e) {
  return (t = void 0 === t ? [] : t)[e = void 0 === e ? 0 : e] = this.x, t[e + 1] = this.y, 
  t[e + 2] = this.z, t;
 },
 fromBufferAttribute: function(t, e, i) {
  return void 0 !== i && console.warn("Vector3: offset has been removed from .fromBufferAttribute()."), 
  this.x = t.getX(e), this.y = t.getY(e), this.z = t.getZ(e), this;
 }
});

const singleton = Symbol(), singletonEnforcer = Symbol(), revision = 1, FRONT_SIDE = 0, BACK_SIDE = 1, FRONT_AND_BACK_SIDE = 2, FUNC_LESS = 3, FUNC_LEQUAL = 4, FUNC_EQUAL = 5, FUNC_NOTEQUAL = 6, FUNC_GREATER = 7, FUNC_GEQUAL = 8, FUNC_NEVER = 9, FUNC_ALWAYS = 10, WEBGL1 = "gl1", WEBGL2 = "gl2", ZeroCurvatureEnding = 2400, ZeroSlopeEnding = 2401, WrapAroundEnding = 2402, FlatShading = 1, GouraudShading = 2, PhongShading = 3, SmoothShading = 4, SPRITE_SPACE_WORLD = 0, SPRITE_SPACE_SCREEN = 1, STRIPE_SPACE_WORLD = 0, STRIPE_SPACE_SCREEN = 1, STRIPE_CAP_DEFAULT = 0, STRIPE_CAP_BUTT = 1, STRIPE_CAP_SQUARE = 2, STRIPE_CAP_ROUND = 3, STRIPE_JOIN_DEFAULT = 0, STRIPE_JOIN_MITER = 1, STRIPE_JOIN_BEVEL = 2, STRIPE_JOIN_ROUND = 3, TEXT2D_SPACE_WORLD = 0, TEXT2D_SPACE_SCREEN = 1, HIGHPASS_MODE_BRIGHTNESS = 0, HIGHPASS_MODE_DIFFERENCE = 1, POINTS = 0, LINES = 1, LINE_LOOP = 2, LINE_STRIP = 3, TRIANGLES = 4, TRIANGLE_STRIP = 5, TRIANGLE_FAN = 6, VERTEX_SHADER = "vertex", FRAGMENT_SHADER = "fragment", SUPPRESS_DEFAULT_KEYBOARD_KEYS = [ 37, 38, 39, 40 ], BLACKLIST = {
 beef: [ "046d" ]
}, gamepadIDRegex = /Vendor:\s+(.*)\s+Product:\s+(.*)\)/, MINVEC = new Vector3(-1, -1, -1), MAXVEC = new Vector3(1, 1, 1);

var _v0 = new Vector3(), _v1$1 = new Vector3(), _v2 = new Vector3(), _v3 = new Vector3(), _vab = new Vector3(), _vac = new Vector3(), _vbc = new Vector3(), _vap = new Vector3(), _vbp = new Vector3(), _vcp = new Vector3();

function Triangle(t, e, i) {
 this.a = void 0 !== t ? t : new Vector3(), this.b = void 0 !== e ? e : new Vector3(), 
 this.c = void 0 !== i ? i : new Vector3();
}

function Spherical(t, e, i) {
 return this.radius = void 0 !== t ? t : 1, this.phi = void 0 !== e ? e : 0, this.theta = void 0 !== i ? i : 0, 
 this;
}

function Cylindrical(t, e, i) {
 return this.radius = void 0 !== t ? t : 1, this.theta = void 0 !== e ? e : 0, this.y = void 0 !== i ? i : 0, 
 this;
}

Object.assign(Triangle, {
 getNormal: function(t, e, i, r) {
  void 0 === r && (console.warn("Triangle: .getNormal() target is now required"), 
  r = new Vector3()), r.subVectors(i, e), _v0.subVectors(t, e), r.cross(_v0);
  i = r.lengthSq();
  return 0 < i ? r.multiplyScalar(1 / Math.sqrt(i)) : r.set(0, 0, 0);
 },
 getBarycoord: function(t, e, i, r, s) {
  _v0.subVectors(r, e), _v1$1.subVectors(i, e), _v2.subVectors(t, e);
  var r = _v0.dot(_v0), i = _v0.dot(_v1$1), t = _v0.dot(_v2), e = _v1$1.dot(_v1$1), a = _v1$1.dot(_v2), n = r * e - i * i;
  return void 0 === s && (console.warn("Triangle: .getBarycoord() target is now required"), 
  s = new Vector3()), 0 == n ? s.set(-2, -1, -1) : s.set(1 - (e = (e * t - i * a) * (s = 1 / n)) - (n = (r * a - i * t) * s), n, e);
 },
 containsPoint: function(t, e, i, r) {
  return Triangle.getBarycoord(t, e, i, r, _v3), 0 <= _v3.x && 0 <= _v3.y && _v3.x + _v3.y <= 1;
 },
 getUV: function(t, e, i, r, s, a, n, o) {
  return this.getBarycoord(t, e, i, r, _v3), o.set(0, 0), o.addScaledVector(s, _v3.x), 
  o.addScaledVector(a, _v3.y), o.addScaledVector(n, _v3.z), o;
 },
 isFrontFacing: function(t, e, i, r) {
  return _v0.subVectors(i, e), _v1$1.subVectors(t, e), _v0.cross(_v1$1).dot(r) < 0;
 }
}), Object.assign(Triangle.prototype, {
 set: function(t, e, i) {
  return this.a.copy(t), this.b.copy(e), this.c.copy(i), this;
 },
 setFromPointsAndIndices: function(t, e, i, r) {
  return this.a.copy(t[e]), this.b.copy(t[i]), this.c.copy(t[r]), this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.a.copy(t.a), this.b.copy(t.b), this.c.copy(t.c), this;
 },
 getArea: function() {
  return _v0.subVectors(this.c, this.b), _v1$1.subVectors(this.a, this.b), .5 * _v0.cross(_v1$1).length();
 },
 getMidpoint: function(t) {
  return void 0 === t && (console.warn("Triangle: .getMidpoint() target is now required"), 
  t = new Vector3()), t.addVectors(this.a, this.b).add(this.c).multiplyScalar(1 / 3);
 },
 getNormal: function(t) {
  return Triangle.getNormal(this.a, this.b, this.c, t);
 },
 getPlane: function(t) {
  return void 0 === t && (console.warn("Triangle: .getPlane() target is now required"), 
  t = new Vector3()), t.setFromCoplanarPoints(this.a, this.b, this.c);
 },
 getBarycoord: function(t, e) {
  return Triangle.getBarycoord(t, this.a, this.b, this.c, e);
 },
 getUV: function(t, e, i, r, s) {
  return Triangle.getUV(t, this.a, this.b, this.c, e, i, r, s);
 },
 containsPoint: function(t) {
  return Triangle.containsPoint(t, this.a, this.b, this.c);
 },
 isFrontFacing: function(t) {
  return Triangle.isFrontFacing(this.a, this.b, this.c, t);
 },
 intersectsBox: function(t) {
  return t.intersectsTriangle(this);
 },
 closestPointToPoint: function(t, e) {
  void 0 === e && (console.warn("Triangle: .closestPointToPoint() target is now required"), 
  e = new Vector3());
  var i = this.a, r = this.b, s = this.c, a = (_vab.subVectors(r, i), _vac.subVectors(s, i), 
  _vap.subVectors(t, i), _vab.dot(_vap)), n = _vac.dot(_vap);
  if (a <= 0 && n <= 0) return e.copy(i);
  _vbp.subVectors(t, r);
  var o = _vab.dot(_vbp), h = _vac.dot(_vbp);
  if (0 <= o && h <= o) return e.copy(r);
  var u = a * h - o * n;
  if (u <= 0 && 0 <= a && o <= 0) return l = a / (a - o), e.copy(i).addScaledVector(_vab, l);
  _vcp.subVectors(t, s);
  var l, _, t = _vab.dot(_vcp), c = _vac.dot(_vcp);
  return 0 <= c && t <= c ? e.copy(s) : (a = t * n - a * c) <= 0 && 0 <= n && c <= 0 ? (_ = n / (n - c), 
  e.copy(i).addScaledVector(_vac, _)) : (n = o * c - t * h) <= 0 && 0 <= h - o && 0 <= t - c ? (_vbc.subVectors(s, r), 
  _ = (h - o) / (h - o + (t - c)), e.copy(r).addScaledVector(_vbc, _)) : (l = a * (s = 1 / (n + a + u)), 
  _ = u * s, e.copy(i).addScaledVector(_vab, l).addScaledVector(_vac, _));
 },
 equals: function(t) {
  return t.a.equals(this.a) && t.b.equals(this.b) && t.c.equals(this.c);
 }
}), Object.assign(Spherical.prototype, {
 set: function(t, e, i) {
  return this.radius = t, this.phi = e, this.theta = i, this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.radius = t.radius, this.phi = t.phi, this.theta = t.theta, this;
 },
 makeSafe: function() {
  return this.phi = Math.max(1e-6, Math.min(Math.PI - 1e-6, this.phi)), this;
 },
 setFromVector3: function(t) {
  return this.setFromCartesianCoords(t.x, t.y, t.z);
 },
 setFromCartesianCoords: function(t, e, i) {
  return this.radius = Math.sqrt(t * t + e * e + i * i), 0 === this.radius ? (this.theta = 0, 
  this.phi = 0) : (this.theta = Math.atan2(t, i), this.phi = Math.acos(_Math.clamp(e / this.radius, -1, 1))), 
  this;
 }
}), Object.assign(Cylindrical.prototype, {
 set: function(t, e, i) {
  return this.radius = t, this.theta = e, this.y = i, this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.radius = t.radius, this.theta = t.theta, this.y = t.y, this;
 },
 setFromVector3: function(t) {
  return this.setFromCartesianCoords(t.x, t.y, t.z);
 },
 setFromCartesianCoords: function(t, e, i) {
  return this.radius = Math.sqrt(t * t + i * i), this.theta = Math.atan2(t, i), 
  this.y = e, this;
 }
});

var _vector$3 = new Vector3();

function Matrix3() {
 this.elements = [ 1, 0, 0, 0, 1, 0, 0, 0, 1 ], 0 < arguments.length && console.error("Matrix3: the constructor no longer reads arguments. use .set() instead.");
}

Object.assign(Matrix3.prototype, {
 isMatrix3: !0,
 set: function(t, e, i, r, s, a, n, o, h) {
  var u = this.elements;
  return u[0] = t, u[1] = r, u[2] = n, u[3] = e, u[4] = s, u[5] = o, u[6] = i, u[7] = a, 
  u[8] = h, this;
 },
 identity: function() {
  return this.set(1, 0, 0, 0, 1, 0, 0, 0, 1), this;
 },
 clone: function() {
  return new this.constructor().fromArray(this.elements);
 },
 copy: function(t) {
  var e = this.elements, t = t.elements;
  return e[0] = t[0], e[1] = t[1], e[2] = t[2], e[3] = t[3], e[4] = t[4], e[5] = t[5], 
  e[6] = t[6], e[7] = t[7], e[8] = t[8], this;
 },
 setFromMatrix4: function(t) {
  t = t.elements;
  return this.set(t[0], t[4], t[8], t[1], t[5], t[9], t[2], t[6], t[10]), this;
 },
 applyToBufferAttribute: function(t) {
  for (var e = 0, i = t.count; e < i; e++) _vector$3.x = t.getX(e), _vector$3.y = t.getY(e), 
  _vector$3.z = t.getZ(e), _vector$3.applyMatrix3(this), t.setXYZ(e, _vector$3.x, _vector$3.y, _vector$3.z);
  return t;
 },
 multiply: function(t) {
  return this.multiplyMatrices(this, t);
 },
 premultiply: function(t) {
  return this.multiplyMatrices(t, this);
 },
 multiplyMatrices: function(t, e) {
  var t = t.elements, e = e.elements, i = this.elements, r = t[0], s = t[3], a = t[6], n = t[1], o = t[4], h = t[7], u = t[2], l = t[5], t = t[8], _ = e[0], c = e[3], d = e[6], m = e[1], g = e[4], p = e[7], f = e[2], y = e[5], e = e[8];
  return i[0] = r * _ + s * m + a * f, i[3] = r * c + s * g + a * y, i[6] = r * d + s * p + a * e, 
  i[1] = n * _ + o * m + h * f, i[4] = n * c + o * g + h * y, i[7] = n * d + o * p + h * e, 
  i[2] = u * _ + l * m + t * f, i[5] = u * c + l * g + t * y, i[8] = u * d + l * p + t * e, 
  this;
 },
 multiplyScalar: function(t) {
  var e = this.elements;
  return e[0] *= t, e[3] *= t, e[6] *= t, e[1] *= t, e[4] *= t, e[7] *= t, e[2] *= t, 
  e[5] *= t, e[8] *= t, this;
 },
 determinant: function() {
  var t = this.elements, e = t[0], i = t[1], r = t[2], s = t[3], a = t[4], n = t[5], o = t[6], h = t[7], t = t[8];
  return e * a * t - e * n * h - i * s * t + i * n * o + r * s * h - r * a * o;
 },
 getInverse: function(t, e) {
  t && t.isMatrix4 && console.error("Matrix3: .getInverse() no longer takes a Matrix4 argument.");
  var t = t.elements, i = this.elements, r = t[0], s = t[1], a = t[2], n = t[3], o = t[4], h = t[5], u = t[6], l = t[7], t = t[8], _ = t * o - h * l, c = h * u - t * n, d = l * n - o * u, m = r * _ + s * c + a * d;
  if (0 == m) {
   var g = "Matrix3: .getInverse() can't invert matrix, determinant is 0";
   if (!0 === e) throw new Error(g);
   return console.warn(g), this.identity();
  }
  e = 1 / m;
  return i[0] = _ * e, i[1] = (a * l - t * s) * e, i[2] = (h * s - a * o) * e, i[3] = c * e, 
  i[4] = (t * r - a * u) * e, i[5] = (a * n - h * r) * e, i[6] = d * e, i[7] = (s * u - l * r) * e, 
  i[8] = (o * r - s * n) * e, this;
 },
 transpose: function() {
  var t = this.elements, e = t[1];
  return t[1] = t[3], t[3] = e, e = t[2], t[2] = t[6], t[6] = e, e = t[5], t[5] = t[7], 
  t[7] = e, this;
 },
 getNormalMatrix: function(t) {
  return this.setFromMatrix4(t).getInverse(this).transpose();
 },
 transposeIntoArray: function(t) {
  var e = this.elements;
  return t[0] = e[0], t[1] = e[3], t[2] = e[6], t[3] = e[1], t[4] = e[4], t[5] = e[7], 
  t[6] = e[2], t[7] = e[5], t[8] = e[8], this;
 },
 setUvTransform: function(t, e, i, r, s, a, n) {
  var o = Math.cos(s), s = Math.sin(s);
  this.set(i * o, i * s, -i * (o * a + s * n) + a + t, -r * s, r * o, -r * (-s * a + o * n) + n + e, 0, 0, 1);
 },
 scale: function(t, e) {
  var i = this.elements;
  return i[0] *= t, i[3] *= t, i[6] *= t, i[1] *= e, i[4] *= e, i[7] *= e, this;
 },
 rotate: function(t) {
  var e = Math.cos(t), t = Math.sin(t), i = this.elements, r = i[0], s = i[3], a = i[6], n = i[1], o = i[4], h = i[7];
  return i[0] = e * r + t * n, i[3] = e * s + t * o, i[6] = e * a + t * h, i[1] = -t * r + e * n, 
  i[4] = -t * s + e * o, i[7] = -t * a + e * h, this;
 },
 translate: function(t, e) {
  var i = this.elements;
  return i[0] += t * i[2], i[3] += t * i[5], i[6] += t * i[8], i[1] += e * i[2], 
  i[4] += e * i[5], i[7] += e * i[8], this;
 },
 equals: function(t) {
  for (var e = this.elements, i = t.elements, r = 0; r < 9; r++) if (e[r] !== i[r]) return !1;
  return !0;
 },
 fromArray: function(t, e) {
  void 0 === e && (e = 0);
  for (var i = 0; i < 9; i++) this.elements[i] = t[i + e];
  return this;
 },
 toArray: function(t, e) {
  var i = this.elements;
  return (t = void 0 === t ? [] : t)[e = void 0 === e ? 0 : e] = i[0], t[e + 1] = i[1], 
  t[e + 2] = i[2], t[e + 3] = i[3], t[e + 4] = i[4], t[e + 5] = i[5], t[e + 6] = i[6], 
  t[e + 7] = i[7], t[e + 8] = i[8], t;
 }
});

var _vector1 = new Vector3(), _vector2 = new Vector3(), _normalMatrix = new Matrix3();

function Plane(t, e) {
 this.normal = void 0 !== t ? t : new Vector3(1, 0, 0), this.constant = void 0 !== e ? e : 0;
}

Object.assign(Plane.prototype, {
 isPlane: !0,
 set: function(t, e) {
  return this.normal.copy(t), this.constant = e, this;
 },
 setComponents: function(t, e, i, r) {
  return this.normal.set(t, e, i), this.constant = r, this;
 },
 setFromNormalAndCoplanarPoint: function(t, e) {
  return this.normal.copy(t), this.constant = -e.dot(this.normal), this;
 },
 setFromCoplanarPoints: function(t, e, i) {
  i = _vector1.subVectors(i, e).cross(_vector2.subVectors(t, e)).normalize();
  return this.setFromNormalAndCoplanarPoint(i, t), this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.normal.copy(t.normal), this.constant = t.constant, this;
 },
 normalize: function() {
  var t = 1 / this.normal.length();
  return this.normal.multiplyScalar(t), this.constant *= t, this;
 },
 negate: function() {
  return this.constant *= -1, this.normal.negate(), this;
 },
 distanceToPoint: function(t) {
  return this.normal.dot(t) + this.constant;
 },
 distanceToSphere: function(t) {
  return this.distanceToPoint(t.center) - t.radius;
 },
 projectPoint: function(t, e) {
  return void 0 === e && (console.warn("Plane: .projectPoint() target is now required"), 
  e = new Vector3()), e.copy(this.normal).multiplyScalar(-this.distanceToPoint(t)).add(t);
 },
 intersectLine: function(t, e) {
  void 0 === e && (console.warn("Plane: .intersectLine() target is now required"), 
  e = new Vector3());
  var i = t.delta(_vector1), r = this.normal.dot(i);
  return 0 === r ? 0 === this.distanceToPoint(t.start) ? e.copy(t.start) : void 0 : (r = -(t.start.dot(this.normal) + this.constant) / r) < 0 || 1 < r ? void 0 : e.copy(i).multiplyScalar(r).add(t.start);
 },
 intersectsLine: function(t) {
  var e = this.distanceToPoint(t.start), t = this.distanceToPoint(t.end);
  return e < 0 && 0 < t || t < 0 && 0 < e;
 },
 intersectsBox: function(t) {
  return t.intersectsPlane(this);
 },
 intersectsSphere: function(t) {
  return t.intersectsPlane(this);
 },
 coplanarPoint: function(t) {
  return void 0 === t && (console.warn("Plane: .coplanarPoint() target is now required"), 
  t = new Vector3()), t.copy(this.normal).multiplyScalar(-this.constant);
 },
 applyMatrix4: function(t, e) {
  e = e || _normalMatrix.getNormalMatrix(t), t = this.coplanarPoint(_vector1).applyMatrix4(t), 
  e = this.normal.applyMatrix3(e).normalize();
  return this.constant = -t.dot(e), this;
 },
 translate: function(t) {
  return this.constant -= t.dot(this.normal), this;
 },
 equals: function(t) {
  return t.normal.equals(this.normal) && t.constant === this.constant;
 }
});

var _sphere = new Sphere(), _vector$2 = new Vector3();

function Frustum(t, e, i, r, s, a) {
 this.planes = [ void 0 !== t ? t : new Plane(), void 0 !== e ? e : new Plane(), void 0 !== i ? i : new Plane(), void 0 !== r ? r : new Plane(), void 0 !== s ? s : new Plane(), void 0 !== a ? a : new Plane() ];
}

Object.assign(Frustum.prototype, {
 set: function(t, e, i, r, s, a) {
  var n = this.planes;
  return n[0].copy(t), n[1].copy(e), n[2].copy(i), n[3].copy(r), n[4].copy(s), n[5].copy(a), 
  this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  for (var e = this.planes, i = 0; i < 6; i++) e[i].copy(t.planes[i]);
  return this;
 },
 setFromMatrix: function(t) {
  var e = this.planes, t = t.elements, i = t[0], r = t[1], s = t[2], a = t[3], n = t[4], o = t[5], h = t[6], u = t[7], l = t[8], _ = t[9], c = t[10], d = t[11], m = t[12], g = t[13], p = t[14], t = t[15];
  return e[0].setComponents(a - i, u - n, d - l, t - m).normalize(), e[1].setComponents(a + i, u + n, d + l, t + m).normalize(), 
  e[2].setComponents(a + r, u + o, d + _, t + g).normalize(), e[3].setComponents(a - r, u - o, d - _, t - g).normalize(), 
  e[4].setComponents(a - s, u - h, d - c, t - p).normalize(), e[5].setComponents(a + s, u + h, d + c, t + p).normalize(), 
  this;
 },
 intersectsObject: function(t) {
  var e = t.geometry;
  return null === e.boundingSphere && e.computeBoundingSphere(), _sphere.copy(e.boundingSphere).applyMatrix4(t.matrixWorld), 
  this.intersectsSphere(_sphere);
 },
 intersectsSprite: function(t) {
  return _sphere.center.set(0, 0, 0), _sphere.radius = .7071067811865476, _sphere.applyMatrix4(t.matrixWorld), 
  this.intersectsSphere(_sphere);
 },
 intersectsSphere: function(t) {
  for (var e = this.planes, i = t.center, r = -t.radius, s = 0; s < 6; s++) if (e[s].distanceToPoint(i) < r) return !1;
  return !0;
 },
 intersectsBox: function(t) {
  for (var e = this.planes, i = 0; i < 6; i++) {
   var r = e[i];
   if (_vector$2.x = (0 < r.normal.x ? t.max : t.min).x, _vector$2.y = (0 < r.normal.y ? t.max : t.min).y, 
   _vector$2.z = (0 < r.normal.z ? t.max : t.min).z, r.distanceToPoint(_vector$2) < 0) return !1;
  }
  return !0;
 },
 containsPoint: function(t) {
  for (var e = this.planes, i = 0; i < 6; i++) if (e[i].distanceToPoint(t) < 0) return !1;
  return !0;
 }
});

var _vector$1 = new Vector3(), _segCenter = new Vector3(), _segDir = new Vector3(), _diff = new Vector3(), _edge1 = new Vector3(), _edge2 = new Vector3(), _normal = new Vector3();

function Ray(t, e) {
 this.origin = void 0 !== t ? t : new Vector3(), this.direction = void 0 !== e ? e : new Vector3();
}

Object.assign(Ray.prototype, {
 set: function(t, e) {
  return this.origin.copy(t), this.direction.copy(e), this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.origin.copy(t.origin), this.direction.copy(t.direction), this;
 },
 at: function(t, e) {
  return void 0 === e && (console.warn("Ray: .at() target is now required"), e = new Vector3()), 
  e.copy(this.direction).multiplyScalar(t).add(this.origin);
 },
 lookAt: function(t) {
  return this.direction.copy(t).sub(this.origin).normalize(), this;
 },
 recast: function(t) {
  return this.origin.copy(this.at(t, _vector$1)), this;
 },
 closestPointToPoint: function(t, e) {
  void 0 === e && (console.warn("Ray: .closestPointToPoint() target is now required"), 
  e = new Vector3()), e.subVectors(t, this.origin);
  t = e.dot(this.direction);
  return t < 0 ? e.copy(this.origin) : e.copy(this.direction).multiplyScalar(t).add(this.origin);
 },
 distanceToPoint: function(t) {
  return Math.sqrt(this.distanceSqToPoint(t));
 },
 distanceSqToPoint: function(t) {
  var e = _vector$1.subVectors(t, this.origin).dot(this.direction);
  return (e < 0 ? this.origin : (_vector$1.copy(this.direction).multiplyScalar(e).add(this.origin), 
  _vector$1)).distanceToSquared(t);
 },
 distanceSqToSegment: function(t, e, i, r) {
  _segCenter.copy(t).add(e).multiplyScalar(.5), _segDir.copy(e).sub(t).normalize(), 
  _diff.copy(this.origin).sub(_segCenter);
  var s, a, n, t = .5 * t.distanceTo(e), e = -this.direction.dot(_segDir), o = _diff.dot(this.direction), h = -_diff.dot(_segDir), u = _diff.lengthSq(), l = Math.abs(1 - e * e);
  return l = 0 < l ? (a = e * o - h, n = t * l, 0 <= (s = e * h - o) ? -n <= a ? a <= n ? (s *= l = 1 / l) * (s + e * (a *= l) + 2 * o) + a * (e * s + a + 2 * h) + u : (a = t, 
  -(s = Math.max(0, -(e * a + o))) * s + a * (a + 2 * h) + u) : (a = -t, -(s = Math.max(0, -(e * a + o))) * s + a * (a + 2 * h) + u) : a <= -n ? -(s = Math.max(0, -(-e * t + o))) * s + (a = 0 < s ? -t : Math.min(Math.max(-t, -h), t)) * (a + 2 * h) + u : a <= n ? (s = 0, 
  (a = Math.min(Math.max(-t, -h), t)) * (a + 2 * h) + u) : -(s = Math.max(0, -(e * t + o))) * s + (a = 0 < s ? t : Math.min(Math.max(-t, -h), t)) * (a + 2 * h) + u) : (a = 0 < e ? -t : t, 
  -(s = Math.max(0, -(e * a + o))) * s + a * (a + 2 * h) + u), i && i.copy(this.direction).multiplyScalar(s).add(this.origin), 
  r && r.copy(_segDir).multiplyScalar(a).add(_segCenter), l;
 },
 intersectSphere: function(t, e) {
  _vector$1.subVectors(t.center, this.origin);
  var i = _vector$1.dot(this.direction), r = _vector$1.dot(_vector$1) - i * i, t = t.radius * t.radius;
  return t < r || (r = i + (t = Math.sqrt(t - r)), (i = i - t) < 0 && r < 0) ? null : i < 0 ? this.at(r, e) : this.at(i, e);
 },
 intersectsSphere: function(t) {
  return this.distanceSqToPoint(t.center) <= t.radius * t.radius;
 },
 distanceToPlane: function(t) {
  var e = t.normal.dot(this.direction);
  return 0 === e ? 0 === t.distanceToPoint(this.origin) ? 0 : null : 0 <= (t = -(this.origin.dot(t.normal) + t.constant) / e) ? t : null;
 },
 intersectPlane: function(t, e) {
  t = this.distanceToPlane(t);
  return null === t ? null : this.at(t, e);
 },
 intersectsPlane: function(t) {
  var e = t.distanceToPoint(this.origin);
  return 0 === e || t.normal.dot(this.direction) * e < 0;
 },
 intersectBox: function(t, e) {
  var i, r, s, a = 1 / this.direction.x, n = 1 / this.direction.y, o = 1 / this.direction.z, h = this.origin, a = 0 <= a ? (i = (t.min.x - h.x) * a, 
  (t.max.x - h.x) * a) : (i = (t.max.x - h.x) * a, (t.min.x - h.x) * a), n = 0 <= n ? (s = (t.min.y - h.y) * n, 
  (t.max.y - h.y) * n) : (s = (t.max.y - h.y) * n, (t.min.y - h.y) * n);
  return n < i || a < s || ((i < s || i != i) && (i = s), (n < a || a != a) && (a = n), 
  (s = 0 <= o ? (r = (t.min.z - h.z) * o, (t.max.z - h.z) * o) : (r = (t.max.z - h.z) * o, 
  (t.min.z - h.z) * o)) < i) || a < r || ((i < r || i != i) && (i = r), (a = s < a || a != a ? s : a) < 0) ? null : this.at(0 <= i ? i : a, e);
 },
 intersectsBox: function(t) {
  return null !== this.intersectBox(t, _vector$1);
 },
 intersectTriangle: function(t, e, i, r, s) {
  _edge1.subVectors(e, t), _edge2.subVectors(i, t), _normal.crossVectors(_edge1, _edge2);
  var a, e = this.direction.dot(_normal);
  if (0 < e) {
   if (r) return null;
   a = 1;
  } else {
   if (!(e < 0)) return null;
   a = -1, e = -e;
  }
  _diff.subVectors(this.origin, t);
  i = a * this.direction.dot(_edge2.crossVectors(_diff, _edge2));
  return i < 0 || (r = a * this.direction.dot(_edge1.cross(_diff))) < 0 || e < i + r || (t = -a * _diff.dot(_normal)) < 0 ? null : this.at(t / e, s);
 },
 applyMatrix4: function(t) {
  return this.origin.applyMatrix4(t), this.direction.transformDirection(t), this;
 },
 equals: function(t) {
  return t.origin.equals(this.origin) && t.direction.equals(this.direction);
 }
});

var _v1 = new Vector3(), _m1 = new Matrix4(), _zero = new Vector3(0, 0, 0), _one = new Vector3(1, 1, 1), _x = new Vector3(), _y = new Vector3(), _z = new Vector3();

function Matrix4() {
 this.elements = [ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ], 0 < arguments.length && console.error("Matrix4: the constructor no longer reads arguments. use .set() instead.");
}

function Vector2(t, e) {
 this.x = t || 0, this.y = e || 0;
}

Object.assign(Matrix4.prototype, {
 isMatrix4: !0,
 set: function(t, e, i, r, s, a, n, o, h, u, l, _, c, d, m, g) {
  var p = this.elements;
  return p[0] = t, p[4] = e, p[8] = i, p[12] = r, p[1] = s, p[5] = a, p[9] = n, 
  p[13] = o, p[2] = h, p[6] = u, p[10] = l, p[14] = _, p[3] = c, p[7] = d, p[11] = m, 
  p[15] = g, this;
 },
 identity: function() {
  return this.set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), this;
 },
 clone: function() {
  return new Matrix4().fromArray(this.elements);
 },
 copy: function(t) {
  var e = this.elements, t = t.elements;
  return e[0] = t[0], e[1] = t[1], e[2] = t[2], e[3] = t[3], e[4] = t[4], e[5] = t[5], 
  e[6] = t[6], e[7] = t[7], e[8] = t[8], e[9] = t[9], e[10] = t[10], e[11] = t[11], 
  e[12] = t[12], e[13] = t[13], e[14] = t[14], e[15] = t[15], this;
 },
 copyPosition: function(t) {
  var e = this.elements, t = t.elements;
  return e[12] = t[12], e[13] = t[13], e[14] = t[14], this;
 },
 extractBasis: function(t, e, i) {
  return t.setFromMatrixColumn(this, 0), e.setFromMatrixColumn(this, 1), i.setFromMatrixColumn(this, 2), 
  this;
 },
 makeBasis: function(t, e, i) {
  return this.set(t.x, e.x, i.x, 0, t.y, e.y, i.y, 0, t.z, e.z, i.z, 0, 0, 0, 0, 1), 
  this;
 },
 extractRotation: function(t) {
  var e = this.elements, i = t.elements, r = 1 / _v1.setFromMatrixColumn(t, 0).length(), s = 1 / _v1.setFromMatrixColumn(t, 1).length(), t = 1 / _v1.setFromMatrixColumn(t, 2).length();
  return e[0] = i[0] * r, e[1] = i[1] * r, e[2] = i[2] * r, e[3] = 0, e[4] = i[4] * s, 
  e[5] = i[5] * s, e[6] = i[6] * s, e[7] = 0, e[8] = i[8] * t, e[9] = i[9] * t, 
  e[10] = i[10] * t, e[11] = 0, e[12] = 0, e[13] = 0, e[14] = 0, e[15] = 1, this;
 },
 makeRotationFromEuler: function(t) {
  t && t.isEuler || console.error("Matrix4: .makeRotationFromEuler() now expects a Euler rotation rather than a Vector3 and order.");
  var e, i, r, s, a, n, o, h, u, l, _, c, d = this.elements, m = t.x, g = t.y, p = t.z, f = Math.cos(m), m = Math.sin(m), y = Math.cos(g), g = Math.sin(g), T = Math.cos(p), p = Math.sin(p);
  return "XYZ" === t.order ? (a = f * T, n = f * p, o = m * T, h = m * p, d[0] = y * T, 
  d[4] = -y * p, d[8] = g, d[1] = n + o * g, d[5] = a - h * g, d[9] = -m * y, d[2] = h - a * g, 
  d[6] = o + n * g, d[10] = f * y) : "YXZ" === t.order ? (i = y * p, r = g * T, 
  d[0] = (e = y * T) + (s = g * p) * m, d[4] = r * m - i, d[8] = f * g, d[1] = f * p, 
  d[5] = f * T, d[9] = -m, d[2] = i * m - r, d[6] = s + e * m, d[10] = f * y) : "ZXY" === t.order ? (i = y * p, 
  r = g * T, d[0] = (e = y * T) - (s = g * p) * m, d[4] = -f * p, d[8] = r + i * m, 
  d[1] = i + r * m, d[5] = f * T, d[9] = s - e * m, d[2] = -f * g, d[6] = m, d[10] = f * y) : "ZYX" === t.order ? (a = f * T, 
  n = f * p, o = m * T, h = m * p, d[0] = y * T, d[4] = o * g - n, d[8] = a * g + h, 
  d[1] = y * p, d[5] = h * g + a, d[9] = n * g - o, d[2] = -g, d[6] = m * y, d[10] = f * y) : "YZX" === t.order ? (u = f * y, 
  l = f * g, _ = m * y, c = m * g, d[0] = y * T, d[4] = c - u * p, d[8] = _ * p + l, 
  d[1] = p, d[5] = f * T, d[9] = -m * T, d[2] = -g * T, d[6] = l * p + _, d[10] = u - c * p) : "XZY" === t.order && (u = f * y, 
  l = f * g, _ = m * y, c = m * g, d[0] = y * T, d[4] = -p, d[8] = g * T, d[1] = u * p + c, 
  d[5] = f * T, d[9] = l * p - _, d[2] = _ * p - l, d[6] = m * T, d[10] = c * p + u), 
  d[3] = 0, d[7] = 0, d[11] = 0, d[12] = 0, d[13] = 0, d[14] = 0, d[15] = 1, this;
 },
 makeRotationFromQuaternion: function(t) {
  return this.compose(_zero, t, _one);
 },
 lookAt: function(t, e, i) {
  var r = this.elements;
  return _z.subVectors(t, e), 0 === _z.lengthSq() && (_z.z = 1), _z.normalize(), 
  _x.crossVectors(i, _z), 0 === _x.lengthSq() && (1 === Math.abs(i.z) ? _z.x += 1e-4 : _z.z += 1e-4, 
  _z.normalize(), _x.crossVectors(i, _z)), _x.normalize(), _y.crossVectors(_z, _x), 
  r[0] = _x.x, r[4] = _y.x, r[8] = _z.x, r[1] = _x.y, r[5] = _y.y, r[9] = _z.y, 
  r[2] = _x.z, r[6] = _y.z, r[10] = _z.z, this;
 },
 multiply: function(t, e) {
  return void 0 !== e ? (console.warn("Matrix4: .multiply() now only accepts one argument. Use .multiplyMatrices( a, b ) instead."), 
  this.multiplyMatrices(t, e)) : this.multiplyMatrices(this, t);
 },
 premultiply: function(t) {
  return this.multiplyMatrices(t, this);
 },
 multiplyMatrices: function(t, e) {
  var t = t.elements, e = e.elements, i = this.elements, r = t[0], s = t[4], a = t[8], n = t[12], o = t[1], h = t[5], u = t[9], l = t[13], _ = t[2], c = t[6], d = t[10], m = t[14], g = t[3], p = t[7], f = t[11], t = t[15], y = e[0], T = e[4], x = e[8], S = e[12], E = e[1], A = e[5], R = e[9], v = e[13], P = e[2], w = e[6], M = e[10], b = e[14], L = e[3], C = e[7], F = e[11], e = e[15];
  return i[0] = r * y + s * E + a * P + n * L, i[4] = r * T + s * A + a * w + n * C, 
  i[8] = r * x + s * R + a * M + n * F, i[12] = r * S + s * v + a * b + n * e, i[1] = o * y + h * E + u * P + l * L, 
  i[5] = o * T + h * A + u * w + l * C, i[9] = o * x + h * R + u * M + l * F, i[13] = o * S + h * v + u * b + l * e, 
  i[2] = _ * y + c * E + d * P + m * L, i[6] = _ * T + c * A + d * w + m * C, i[10] = _ * x + c * R + d * M + m * F, 
  i[14] = _ * S + c * v + d * b + m * e, i[3] = g * y + p * E + f * P + t * L, i[7] = g * T + p * A + f * w + t * C, 
  i[11] = g * x + p * R + f * M + t * F, i[15] = g * S + p * v + f * b + t * e, 
  this;
 },
 multiplyScalar: function(t) {
  var e = this.elements;
  return e[0] *= t, e[4] *= t, e[8] *= t, e[12] *= t, e[1] *= t, e[5] *= t, e[9] *= t, 
  e[13] *= t, e[2] *= t, e[6] *= t, e[10] *= t, e[14] *= t, e[3] *= t, e[7] *= t, 
  e[11] *= t, e[15] *= t, this;
 },
 applyToBufferAttribute: function(t) {
  for (var e = 0, i = t.count; e < i; e++) _v1.x = t.getX(e), _v1.y = t.getY(e), 
  _v1.z = t.getZ(e), _v1.applyMatrix4(this), t.setXYZ(e, _v1.x, _v1.y, _v1.z);
  return t;
 },
 determinant: function() {
  var t = this.elements, e = t[0], i = t[4], r = t[8], s = t[12], a = t[1], n = t[5], o = t[9], h = t[13], u = t[2], l = t[6], _ = t[10], c = t[14];
  return t[3] * (+s * o * l - r * h * l - s * n * _ + i * h * _ + r * n * c - i * o * c) + t[7] * (+e * o * c - e * h * _ + s * a * _ - r * a * c + r * h * u - s * o * u) + t[11] * (+e * h * l - e * n * c - s * a * l + i * a * c + s * n * u - i * h * u) + t[15] * (-r * n * u - e * o * l + e * n * _ + r * a * l - i * a * _ + i * o * u);
 },
 transpose: function() {
  var t = this.elements, e = t[1];
  return t[1] = t[4], t[4] = e, e = t[2], t[2] = t[8], t[8] = e, e = t[6], t[6] = t[9], 
  t[9] = e, e = t[3], t[3] = t[12], t[12] = e, e = t[7], t[7] = t[13], t[13] = e, 
  e = t[11], t[11] = t[14], t[14] = e, this;
 },
 setPosition: function(t, e, i) {
  var r = this.elements;
  return t.isVector3 ? (r[12] = t.x, r[13] = t.y, r[14] = t.z) : (r[12] = t, r[13] = e, 
  r[14] = i), this;
 },
 getInverse: function(t, e) {
  var i = this.elements, t = t.elements, r = t[0], s = t[1], a = t[2], n = t[3], o = t[4], h = t[5], u = t[6], l = t[7], _ = t[8], c = t[9], d = t[10], m = t[11], g = t[12], p = t[13], f = t[14], t = t[15], y = c * f * l - p * d * l + p * u * m - h * f * m - c * u * t + h * d * t, T = g * d * l - _ * f * l - g * u * m + o * f * m + _ * u * t - o * d * t, x = _ * p * l - g * c * l + g * h * m - o * p * m - _ * h * t + o * c * t, S = g * c * u - _ * p * u - g * h * d + o * p * d + _ * h * f - o * c * f, E = r * y + s * T + a * x + n * S;
  if (0 == E) {
   var A = "Matrix4: .getInverse() can't invert matrix, determinant is 0";
   if (!0 === e) throw new Error(A);
   return console.warn(A), this.identity();
  }
  e = 1 / E;
  return i[0] = y * e, i[1] = (p * d * n - c * f * n - p * a * m + s * f * m + c * a * t - s * d * t) * e, 
  i[2] = (h * f * n - p * u * n + p * a * l - s * f * l - h * a * t + s * u * t) * e, 
  i[3] = (c * u * n - h * d * n - c * a * l + s * d * l + h * a * m - s * u * m) * e, 
  i[4] = T * e, i[5] = (_ * f * n - g * d * n + g * a * m - r * f * m - _ * a * t + r * d * t) * e, 
  i[6] = (g * u * n - o * f * n - g * a * l + r * f * l + o * a * t - r * u * t) * e, 
  i[7] = (o * d * n - _ * u * n + _ * a * l - r * d * l - o * a * m + r * u * m) * e, 
  i[8] = x * e, i[9] = (g * c * n - _ * p * n - g * s * m + r * p * m + _ * s * t - r * c * t) * e, 
  i[10] = (o * p * n - g * h * n + g * s * l - r * p * l - o * s * t + r * h * t) * e, 
  i[11] = (_ * h * n - o * c * n - _ * s * l + r * c * l + o * s * m - r * h * m) * e, 
  i[12] = S * e, i[13] = (_ * p * a - g * c * a + g * s * d - r * p * d - _ * s * f + r * c * f) * e, 
  i[14] = (g * h * a - o * p * a - g * s * u + r * p * u + o * s * f - r * h * f) * e, 
  i[15] = (o * c * a - _ * h * a + _ * s * u - r * c * u - o * s * d + r * h * d) * e, 
  this;
 },
 scale: function(t) {
  var e = this.elements, i = t.x, r = t.y, t = t.z;
  return e[0] *= i, e[4] *= r, e[8] *= t, e[1] *= i, e[5] *= r, e[9] *= t, e[2] *= i, 
  e[6] *= r, e[10] *= t, e[3] *= i, e[7] *= r, e[11] *= t, this;
 },
 getMaxScaleOnAxis: function() {
  var t = this.elements, e = t[0] * t[0] + t[1] * t[1] + t[2] * t[2], i = t[4] * t[4] + t[5] * t[5] + t[6] * t[6], t = t[8] * t[8] + t[9] * t[9] + t[10] * t[10];
  return Math.sqrt(Math.max(e, i, t));
 },
 makeTranslation: function(t, e, i) {
  return this.set(1, 0, 0, t, 0, 1, 0, e, 0, 0, 1, i, 0, 0, 0, 1), this;
 },
 makeRotationX: function(t) {
  var e = Math.cos(t), t = Math.sin(t);
  return this.set(1, 0, 0, 0, 0, e, -t, 0, 0, t, e, 0, 0, 0, 0, 1), this;
 },
 makeRotationY: function(t) {
  var e = Math.cos(t), t = Math.sin(t);
  return this.set(e, 0, t, 0, 0, 1, 0, 0, -t, 0, e, 0, 0, 0, 0, 1), this;
 },
 makeRotationZ: function(t) {
  var e = Math.cos(t), t = Math.sin(t);
  return this.set(e, -t, 0, 0, t, e, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), this;
 },
 makeRotationAxis: function(t, e) {
  var i = Math.cos(e), e = Math.sin(e), r = 1 - i, s = t.x, a = t.y, t = t.z, n = r * s, o = r * a;
  return this.set(n * s + i, n * a - e * t, n * t + e * a, 0, n * a + e * t, o * a + i, o * t - e * s, 0, n * t - e * a, o * t + e * s, r * t * t + i, 0, 0, 0, 0, 1), 
  this;
 },
 makeScale: function(t, e, i) {
  return this.set(t, 0, 0, 0, 0, e, 0, 0, 0, 0, i, 0, 0, 0, 0, 1), this;
 },
 makeShear: function(t, e, i) {
  return this.set(1, e, i, 0, t, 1, i, 0, t, e, 1, 0, 0, 0, 0, 1), this;
 },
 compose: function(t, e, i) {
  var r = this.elements, s = e._x, a = e._y, n = e._z, e = e._w, o = s + s, h = a + a, u = n + n, l = s * o, _ = s * h, s = s * u, c = a * h, a = a * u, n = n * u, o = e * o, h = e * h, e = e * u, u = i.x, d = i.y, i = i.z;
  return r[0] = (1 - (c + n)) * u, r[1] = (_ + e) * u, r[2] = (s - h) * u, r[3] = 0, 
  r[4] = (_ - e) * d, r[5] = (1 - (l + n)) * d, r[6] = (a + o) * d, r[7] = 0, r[8] = (s + h) * i, 
  r[9] = (a - o) * i, r[10] = (1 - (l + c)) * i, r[11] = 0, r[12] = t.x, r[13] = t.y, 
  r[14] = t.z, r[15] = 1, this;
 },
 decompose: function(t, e, i) {
  var r = this.elements, s = _v1.set(r[0], r[1], r[2]).length(), a = _v1.set(r[4], r[5], r[6]).length(), n = _v1.set(r[8], r[9], r[10]).length(), t = (this.determinant() < 0 && (s = -s), 
  t.x = r[12], t.y = r[13], t.z = r[14], _m1.copy(this), 1 / s), r = 1 / a, o = 1 / n;
  return _m1.elements[0] *= t, _m1.elements[1] *= t, _m1.elements[2] *= t, _m1.elements[4] *= r, 
  _m1.elements[5] *= r, _m1.elements[6] *= r, _m1.elements[8] *= o, _m1.elements[9] *= o, 
  _m1.elements[10] *= o, e.setFromRotationMatrix(_m1), i.x = s, i.y = a, i.z = n, 
  this;
 },
 makePerspective: function(t, e, i, r, s, a) {
  void 0 === a && console.warn("Matrix4: .makePerspective() has been redefined and has a new signature. Please check the docs.");
  var n = this.elements, o = 2 * s / (i - r), h = (e + t) / (e - t), i = (i + r) / (i - r), r = -(a + s) / (a - s), a = -2 * a * s / (a - s);
  return n[0] = 2 * s / (e - t), n[4] = 0, n[8] = h, n[12] = 0, n[1] = 0, n[5] = o, 
  n[9] = i, n[13] = 0, n[2] = 0, n[6] = 0, n[10] = r, n[14] = a, n[3] = 0, n[7] = 0, 
  n[11] = -1, n[15] = 0, this;
 },
 makeOrthographic: function(t, e, i, r, s, a) {
  var n = this.elements, o = 1 / (e - t), h = 1 / (i - r), u = 1 / (a - s), e = (e + t) * o, t = (i + r) * h, i = (a + s) * u;
  return n[0] = 2 * o, n[4] = 0, n[8] = 0, n[12] = -e, n[1] = 0, n[5] = 2 * h, n[9] = 0, 
  n[13] = -t, n[2] = 0, n[6] = 0, n[10] = -2 * u, n[14] = -i, n[3] = 0, n[7] = 0, 
  n[11] = 0, n[15] = 1, this;
 },
 equals: function(t) {
  for (var e = this.elements, i = t.elements, r = 0; r < 16; r++) if (e[r] !== i[r]) return !1;
  return !0;
 },
 fromArray: function(t, e) {
  void 0 === e && (e = 0);
  for (var i = 0; i < 16; i++) this.elements[i] = t[i + e];
  return this;
 },
 toArray: function(t, e) {
  var i = this.elements;
  return (t = void 0 === t ? [] : t)[e = void 0 === e ? 0 : e] = i[0], t[e + 1] = i[1], 
  t[e + 2] = i[2], t[e + 3] = i[3], t[e + 4] = i[4], t[e + 5] = i[5], t[e + 6] = i[6], 
  t[e + 7] = i[7], t[e + 8] = i[8], t[e + 9] = i[9], t[e + 10] = i[10], t[e + 11] = i[11], 
  t[e + 12] = i[12], t[e + 13] = i[13], t[e + 14] = i[14], t[e + 15] = i[15], t;
 }
}), Object.defineProperties(Vector2.prototype, {
 width: {
  get: function() {
   return this.x;
  },
  set: function(t) {
   this.x = t;
  }
 },
 height: {
  get: function() {
   return this.y;
  },
  set: function(t) {
   this.y = t;
  }
 }
}), Object.assign(Vector2.prototype, {
 isVector2: !0,
 set: function(t, e) {
  return this.x = t, this.y = e, this;
 },
 setScalar: function(t) {
  return this.x = t, this.y = t, this;
 },
 setX: function(t) {
  return this.x = t, this;
 },
 setY: function(t) {
  return this.y = t, this;
 },
 setComponent: function(t, e) {
  switch (t) {
  case 0:
   this.x = e;
   break;

  case 1:
   this.y = e;
   break;

  default:
   throw new Error("index is out of range: " + t);
  }
  return this;
 },
 getComponent: function(t) {
  switch (t) {
  case 0:
   return this.x;

  case 1:
   return this.y;

  default:
   throw new Error("index is out of range: " + t);
  }
 },
 clone: function() {
  return new this.constructor(this.x, this.y);
 },
 copy: function(t) {
  return this.x = t.x, this.y = t.y, this;
 },
 add: function(t, e) {
  return void 0 !== e ? (console.warn("Vector2: .add() now only accepts one argument. Use .addVectors( a, b ) instead."), 
  this.addVectors(t, e)) : (this.x += t.x, this.y += t.y, this);
 },
 addScalar: function(t) {
  return this.x += t, this.y += t, this;
 },
 addVectors: function(t, e) {
  return this.x = t.x + e.x, this.y = t.y + e.y, this;
 },
 addScaledVector: function(t, e) {
  return this.x += t.x * e, this.y += t.y * e, this;
 },
 sub: function(t, e) {
  return void 0 !== e ? (console.warn("Vector2: .sub() now only accepts one argument. Use .subVectors( a, b ) instead."), 
  this.subVectors(t, e)) : (this.x -= t.x, this.y -= t.y, this);
 },
 subScalar: function(t) {
  return this.x -= t, this.y -= t, this;
 },
 subVectors: function(t, e) {
  return this.x = t.x - e.x, this.y = t.y - e.y, this;
 },
 multiply: function(t) {
  return this.x *= t.x, this.y *= t.y, this;
 },
 multiplyScalar: function(t) {
  return this.x *= t, this.y *= t, this;
 },
 divide: function(t) {
  return this.x /= t.x, this.y /= t.y, this;
 },
 divideScalar: function(t) {
  return this.multiplyScalar(1 / t);
 },
 applyMatrix3: function(t) {
  var e = this.x, i = this.y, t = t.elements;
  return this.x = t[0] * e + t[3] * i + t[6], this.y = t[1] * e + t[4] * i + t[7], 
  this;
 },
 min: function(t) {
  return this.x = Math.min(this.x, t.x), this.y = Math.min(this.y, t.y), this;
 },
 max: function(t) {
  return this.x = Math.max(this.x, t.x), this.y = Math.max(this.y, t.y), this;
 },
 clamp: function(t, e) {
  return this.x = Math.max(t.x, Math.min(e.x, this.x)), this.y = Math.max(t.y, Math.min(e.y, this.y)), 
  this;
 },
 clampScalar: function(t, e) {
  return this.x = Math.max(t, Math.min(e, this.x)), this.y = Math.max(t, Math.min(e, this.y)), 
  this;
 },
 clampLength: function(t, e) {
  var i = this.length();
  return this.divideScalar(i || 1).multiplyScalar(Math.max(t, Math.min(e, i)));
 },
 floor: function() {
  return this.x = Math.floor(this.x), this.y = Math.floor(this.y), this;
 },
 ceil: function() {
  return this.x = Math.ceil(this.x), this.y = Math.ceil(this.y), this;
 },
 round: function() {
  return this.x = Math.round(this.x), this.y = Math.round(this.y), this;
 },
 roundToZero: function() {
  return this.x = this.x < 0 ? Math.ceil(this.x) : Math.floor(this.x), this.y = this.y < 0 ? Math.ceil(this.y) : Math.floor(this.y), 
  this;
 },
 negate: function() {
  return this.x = -this.x, this.y = -this.y, this;
 },
 dot: function(t) {
  return this.x * t.x + this.y * t.y;
 },
 cross: function(t) {
  return this.x * t.y - this.y * t.x;
 },
 lengthSq: function() {
  return this.x * this.x + this.y * this.y;
 },
 length: function() {
  return Math.sqrt(this.x * this.x + this.y * this.y);
 },
 manhattanLength: function() {
  return Math.abs(this.x) + Math.abs(this.y);
 },
 normalize: function() {
  return this.divideScalar(this.length() || 1);
 },
 angle: function() {
  var t = Math.atan2(this.y, this.x);
  return t < 0 && (t += 2 * Math.PI), t;
 },
 distanceTo: function(t) {
  return Math.sqrt(this.distanceToSquared(t));
 },
 distanceToSquared: function(t) {
  var e = this.x - t.x, t = this.y - t.y;
  return e * e + t * t;
 },
 manhattanDistanceTo: function(t) {
  return Math.abs(this.x - t.x) + Math.abs(this.y - t.y);
 },
 setLength: function(t) {
  return this.normalize().multiplyScalar(t);
 },
 lerp: function(t, e) {
  return this.x += (t.x - this.x) * e, this.y += (t.y - this.y) * e, this;
 },
 lerpVectors: function(t, e, i) {
  return this.subVectors(e, t).multiplyScalar(i).add(t);
 },
 equals: function(t) {
  return t.x === this.x && t.y === this.y;
 },
 fromArray: function(t, e) {
  return this.x = t[e = void 0 === e ? 0 : e], this.y = t[e + 1], this;
 },
 toArray: function(t, e) {
  return (t = void 0 === t ? [] : t)[e = void 0 === e ? 0 : e] = this.x, t[e + 1] = this.y, 
  t;
 },
 fromBufferAttribute: function(t, e, i) {
  return void 0 !== i && console.warn("Vector2: offset has been removed from .fromBufferAttribute()."), 
  this.x = t.getX(e), this.y = t.getY(e), this;
 },
 rotateAround: function(t, e) {
  var i = Math.cos(e), e = Math.sin(e), r = this.x - t.x, s = this.y - t.y;
  return this.x = r * i - s * e + t.x, this.y = r * e + s * i + t.y, this;
 }
});

var _vector = new Vector2();

function Box2(t, e) {
 this.min = void 0 !== t ? t : new Vector2(1 / 0, 1 / 0), this.max = void 0 !== e ? e : new Vector2(-1 / 0, -1 / 0);
}

Object.assign(Box2.prototype, {
 set: function(t, e) {
  return this.min.copy(t), this.max.copy(e), this;
 },
 setFromPoints: function(t) {
  this.makeEmpty();
  for (var e = 0, i = t.length; e < i; e++) this.expandByPoint(t[e]);
  return this;
 },
 setFromCenterAndSize: function(t, e) {
  e = _vector.copy(e).multiplyScalar(.5);
  return this.min.copy(t).sub(e), this.max.copy(t).add(e), this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.min.copy(t.min), this.max.copy(t.max), this;
 },
 makeEmpty: function() {
  return this.min.x = this.min.y = 1 / 0, this.max.x = this.max.y = -1 / 0, this;
 },
 isEmpty: function() {
  return this.max.x < this.min.x || this.max.y < this.min.y;
 },
 getCenter: function(t) {
  return void 0 === t && (console.warn("Box2: .getCenter() target is now required"), 
  t = new Vector2()), this.isEmpty() ? t.set(0, 0) : t.addVectors(this.min, this.max).multiplyScalar(.5);
 },
 getSize: function(t) {
  return void 0 === t && (console.warn("Box2: .getSize() target is now required"), 
  t = new Vector2()), this.isEmpty() ? t.set(0, 0) : t.subVectors(this.max, this.min);
 },
 expandByPoint: function(t) {
  return this.min.min(t), this.max.max(t), this;
 },
 expandByVector: function(t) {
  return this.min.sub(t), this.max.add(t), this;
 },
 expandByScalar: function(t) {
  return this.min.addScalar(-t), this.max.addScalar(t), this;
 },
 containsPoint: function(t) {
  return !(t.x < this.min.x || t.x > this.max.x || t.y < this.min.y || t.y > this.max.y);
 },
 containsBox: function(t) {
  return this.min.x <= t.min.x && t.max.x <= this.max.x && this.min.y <= t.min.y && t.max.y <= this.max.y;
 },
 getParameter: function(t, e) {
  return void 0 === e && (console.warn("Box2: .getParameter() target is now required"), 
  e = new Vector2()), e.set((t.x - this.min.x) / (this.max.x - this.min.x), (t.y - this.min.y) / (this.max.y - this.min.y));
 },
 intersectsBox: function(t) {
  return !(t.max.x < this.min.x || t.min.x > this.max.x || t.max.y < this.min.y || t.min.y > this.max.y);
 },
 clampPoint: function(t, e) {
  return void 0 === e && (console.warn("Box2: .clampPoint() target is now required"), 
  e = new Vector2()), e.copy(t).clamp(this.min, this.max);
 },
 distanceToPoint: function(t) {
  return _vector.copy(t).clamp(this.min, this.max).sub(t).length();
 },
 intersect: function(t) {
  return this.min.max(t.min), this.max.min(t.max), this;
 },
 union: function(t) {
  return this.min.min(t.min), this.max.max(t.max), this;
 },
 translate: function(t) {
  return this.min.add(t), this.max.add(t), this;
 },
 equals: function(t) {
  return t.min.equals(this.min) && t.max.equals(this.max);
 }
});

var _startP = new Vector3(), _startEnd = new Vector3();

function Line3(t, e) {
 this.start = void 0 !== t ? t : new Vector3(), this.end = void 0 !== e ? e : new Vector3();
}

Object.assign(Line3.prototype, {
 set: function(t, e) {
  return this.start.copy(t), this.end.copy(e), this;
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 copy: function(t) {
  return this.start.copy(t.start), this.end.copy(t.end), this;
 },
 getCenter: function(t) {
  return void 0 === t && (console.warn("Line3: .getCenter() target is now required"), 
  t = new Vector3()), t.addVectors(this.start, this.end).multiplyScalar(.5);
 },
 delta: function(t) {
  return void 0 === t && (console.warn("Line3: .delta() target is now required"), 
  t = new Vector3()), t.subVectors(this.end, this.start);
 },
 distanceSq: function() {
  return this.start.distanceToSquared(this.end);
 },
 distance: function() {
  return this.start.distanceTo(this.end);
 },
 at: function(t, e) {
  return void 0 === e && (console.warn("Line3: .at() target is now required"), e = new Vector3()), 
  this.delta(e).multiplyScalar(t).add(this.start);
 },
 closestPointToPointParameter: function(t, e) {
  _startP.subVectors(t, this.start), _startEnd.subVectors(this.end, this.start);
  t = _startEnd.dot(_startEnd), t = _startEnd.dot(_startP) / t;
  return t = e ? _Math.clamp(t, 0, 1) : t;
 },
 closestPointToPoint: function(t, e, i) {
  t = this.closestPointToPointParameter(t, e);
  return void 0 === i && (console.warn("Line3: .closestPointToPoint() target is now required"), 
  i = new Vector3()), this.delta(i).multiplyScalar(t).add(this.start);
 },
 applyMatrix4: function(t) {
  return this.start.applyMatrix4(t), this.end.applyMatrix4(t), this;
 },
 equals: function(t) {
  return t.start.equals(this.start) && t.end.equals(this.end);
 }
});

var _matrix = new Matrix4(), _quaternion = new Quaternion();

function Euler(t, e, i, r) {
 this._x = t || 0, this._y = e || 0, this._z = i || 0, this._order = r || Euler.DefaultOrder;
}

function Vector4(t, e, i, r) {
 this.x = t || 0, this.y = e || 0, this.z = i || 0, this.w = void 0 !== r ? r : 1;
}

Euler.RotationOrders = [ "XYZ", "YZX", "ZXY", "XZY", "YXZ", "ZYX" ], Euler.DefaultOrder = "XYZ", 
Object.defineProperties(Euler.prototype, {
 x: {
  get: function() {
   return this._x;
  },
  set: function(t) {
   this._x = t, this._onChangeCallback();
  }
 },
 y: {
  get: function() {
   return this._y;
  },
  set: function(t) {
   this._y = t, this._onChangeCallback();
  }
 },
 z: {
  get: function() {
   return this._z;
  },
  set: function(t) {
   this._z = t, this._onChangeCallback();
  }
 },
 order: {
  get: function() {
   return this._order;
  },
  set: function(t) {
   this._order = t, this._onChangeCallback();
  }
 }
}), Object.assign(Euler.prototype, {
 isEuler: !0,
 set: function(t, e, i, r) {
  return this._x = t, this._y = e, this._z = i, this._order = r || this._order, 
  this._onChangeCallback(), this;
 },
 clone: function() {
  return new this.constructor(this._x, this._y, this._z, this._order);
 },
 copy: function(t) {
  return this._x = t._x, this._y = t._y, this._z = t._z, this._order = t._order, 
  this._onChangeCallback(), this;
 },
 setFromRotationMatrix: function(t, e, i) {
  var r = _Math.clamp, t = t.elements, s = t[0], a = t[4], n = t[8], o = t[1], h = t[5], u = t[9], l = t[2], _ = t[6], t = t[10];
  return "XYZ" === (e = e || this._order) ? (this._y = Math.asin(r(n, -1, 1)), Math.abs(n) < .9999999 ? (this._x = Math.atan2(-u, t), 
  this._z = Math.atan2(-a, s)) : (this._x = Math.atan2(_, h), this._z = 0)) : "YXZ" === e ? (this._x = Math.asin(-r(u, -1, 1)), 
  Math.abs(u) < .9999999 ? (this._y = Math.atan2(n, t), this._z = Math.atan2(o, h)) : (this._y = Math.atan2(-l, s), 
  this._z = 0)) : "ZXY" === e ? (this._x = Math.asin(r(_, -1, 1)), Math.abs(_) < .9999999 ? (this._y = Math.atan2(-l, t), 
  this._z = Math.atan2(-a, h)) : (this._y = 0, this._z = Math.atan2(o, s))) : "ZYX" === e ? (this._y = Math.asin(-r(l, -1, 1)), 
  Math.abs(l) < .9999999 ? (this._x = Math.atan2(_, t), this._z = Math.atan2(o, s)) : (this._x = 0, 
  this._z = Math.atan2(-a, h))) : "YZX" === e ? (this._z = Math.asin(r(o, -1, 1)), 
  Math.abs(o) < .9999999 ? (this._x = Math.atan2(-u, h), this._y = Math.atan2(-l, s)) : (this._x = 0, 
  this._y = Math.atan2(n, t))) : "XZY" === e ? (this._z = Math.asin(-r(a, -1, 1)), 
  Math.abs(a) < .9999999 ? (this._x = Math.atan2(_, h), this._y = Math.atan2(n, s)) : (this._x = Math.atan2(-u, t), 
  this._y = 0)) : console.warn("Euler: .setFromRotationMatrix() given unsupported order: " + e), 
  this._order = e, !1 !== i && this._onChangeCallback(), this;
 },
 setFromQuaternion: function(t, e, i) {
  return _matrix.makeRotationFromQuaternion(t), this.setFromRotationMatrix(_matrix, e, i);
 },
 setFromVector3: function(t, e) {
  return this.set(t.x, t.y, t.z, e || this._order);
 },
 reorder: function(t) {
  return _quaternion.setFromEuler(this), this.setFromQuaternion(_quaternion, t);
 },
 equals: function(t) {
  return t._x === this._x && t._y === this._y && t._z === this._z && t._order === this._order;
 },
 fromArray: function(t) {
  return this._x = t[0], this._y = t[1], this._z = t[2], void 0 !== t[3] && (this._order = t[3]), 
  this._onChangeCallback(), this;
 },
 toArray: function(t, e) {
  return (t = void 0 === t ? [] : t)[e = void 0 === e ? 0 : e] = this._x, t[e + 1] = this._y, 
  t[e + 2] = this._z, t[e + 3] = this._order, t;
 },
 toVector3: function(t) {
  return t ? t.set(this._x, this._y, this._z) : new Vector3(this._x, this._y, this._z);
 },
 _onChange: function(t) {
  return this._onChangeCallback = t, this;
 },
 _onChangeCallback: function() {}
}), Object.defineProperties(Vector4.prototype, {
 width: {
  get: function() {
   return this.z;
  },
  set: function(t) {
   this.z = t;
  }
 },
 height: {
  get: function() {
   return this.w;
  },
  set: function(t) {
   this.w = t;
  }
 }
}), Object.assign(Vector4.prototype, {
 isVector4: !0,
 set: function(t, e, i, r) {
  return this.x = t, this.y = e, this.z = i, this.w = r, this;
 },
 setScalar: function(t) {
  return this.x = t, this.y = t, this.z = t, this.w = t, this;
 },
 setX: function(t) {
  return this.x = t, this;
 },
 setY: function(t) {
  return this.y = t, this;
 },
 setZ: function(t) {
  return this.z = t, this;
 },
 setW: function(t) {
  return this.w = t, this;
 },
 setComponent: function(t, e) {
  switch (t) {
  case 0:
   this.x = e;
   break;

  case 1:
   this.y = e;
   break;

  case 2:
   this.z = e;
   break;

  case 3:
   this.w = e;
   break;

  default:
   throw new Error("index is out of range: " + t);
  }
  return this;
 },
 getComponent: function(t) {
  switch (t) {
  case 0:
   return this.x;

  case 1:
   return this.y;

  case 2:
   return this.z;

  case 3:
   return this.w;

  default:
   throw new Error("index is out of range: " + t);
  }
 },
 clone: function() {
  return new this.constructor(this.x, this.y, this.z, this.w);
 },
 copy: function(t) {
  return this.x = t.x, this.y = t.y, this.z = t.z, this.w = void 0 !== t.w ? t.w : 1, 
  this;
 },
 add: function(t, e) {
  return void 0 !== e ? (console.warn("Vector4: .add() now only accepts one argument. Use .addVectors( a, b ) instead."), 
  this.addVectors(t, e)) : (this.x += t.x, this.y += t.y, this.z += t.z, this.w += t.w, 
  this);
 },
 addScalar: function(t) {
  return this.x += t, this.y += t, this.z += t, this.w += t, this;
 },
 addVectors: function(t, e) {
  return this.x = t.x + e.x, this.y = t.y + e.y, this.z = t.z + e.z, this.w = t.w + e.w, 
  this;
 },
 addScaledVector: function(t, e) {
  return this.x += t.x * e, this.y += t.y * e, this.z += t.z * e, this.w += t.w * e, 
  this;
 },
 sub: function(t, e) {
  return void 0 !== e ? (console.warn("Vector4: .sub() now only accepts one argument. Use .subVectors( a, b ) instead."), 
  this.subVectors(t, e)) : (this.x -= t.x, this.y -= t.y, this.z -= t.z, this.w -= t.w, 
  this);
 },
 subScalar: function(t) {
  return this.x -= t, this.y -= t, this.z -= t, this.w -= t, this;
 },
 subVectors: function(t, e) {
  return this.x = t.x - e.x, this.y = t.y - e.y, this.z = t.z - e.z, this.w = t.w - e.w, 
  this;
 },
 multiplyScalar: function(t) {
  return this.x *= t, this.y *= t, this.z *= t, this.w *= t, this;
 },
 applyMatrix4: function(t) {
  var e = this.x, i = this.y, r = this.z, s = this.w, t = t.elements;
  return this.x = t[0] * e + t[4] * i + t[8] * r + t[12] * s, this.y = t[1] * e + t[5] * i + t[9] * r + t[13] * s, 
  this.z = t[2] * e + t[6] * i + t[10] * r + t[14] * s, this.w = t[3] * e + t[7] * i + t[11] * r + t[15] * s, 
  this;
 },
 divideScalar: function(t) {
  return this.multiplyScalar(1 / t);
 },
 setAxisAngleFromQuaternion: function(t) {
  this.w = 2 * Math.acos(t.w);
  var e = Math.sqrt(1 - t.w * t.w);
  return e < 1e-4 ? (this.x = 1, this.y = 0, this.z = 0) : (this.x = t.x / e, this.y = t.y / e, 
  this.z = t.z / e), this;
 },
 setAxisAngleFromRotationMatrix: function(t) {
  var e, i, r, s, a, n, o, h, u, l, t = t.elements, _ = t[0], c = t[4], d = t[8], m = t[1], g = t[5], p = t[9], f = t[2], y = t[6], t = t[10];
  return Math.abs(c - m) < .01 && Math.abs(d - f) < .01 && Math.abs(p - y) < .01 ? Math.abs(c + m) < .1 && Math.abs(d + f) < .1 && Math.abs(p + y) < .1 && Math.abs(_ + g + t - 3) < .1 ? this.set(1, 0, 0, 0) : (s = Math.PI, 
  n = (t + 1) / 2, o = (c + m) / 4, h = (d + f) / 4, u = (p + y) / 4, (a = (g + 1) / 2) < (l = (_ + 1) / 2) && n < l ? r = l < .01 ? (e = 0, 
  i = .707106781) : (i = o / (e = Math.sqrt(l)), h / e) : n < a ? r = a < .01 ? (i = 0, 
  e = .707106781) : (e = o / (i = Math.sqrt(a)), u / i) : n < .01 ? (i = e = .707106781, 
  r = 0) : (e = h / (r = Math.sqrt(n)), i = u / r), this.set(e, i, r, s)) : (l = Math.sqrt((y - p) * (y - p) + (d - f) * (d - f) + (m - c) * (m - c)), 
  Math.abs(l) < .001 && (l = 1), this.x = (y - p) / l, this.y = (d - f) / l, this.z = (m - c) / l, 
  this.w = Math.acos((_ + g + t - 1) / 2)), this;
 },
 min: function(t) {
  return this.x = Math.min(this.x, t.x), this.y = Math.min(this.y, t.y), this.z = Math.min(this.z, t.z), 
  this.w = Math.min(this.w, t.w), this;
 },
 max: function(t) {
  return this.x = Math.max(this.x, t.x), this.y = Math.max(this.y, t.y), this.z = Math.max(this.z, t.z), 
  this.w = Math.max(this.w, t.w), this;
 },
 clamp: function(t, e) {
  return this.x = Math.max(t.x, Math.min(e.x, this.x)), this.y = Math.max(t.y, Math.min(e.y, this.y)), 
  this.z = Math.max(t.z, Math.min(e.z, this.z)), this.w = Math.max(t.w, Math.min(e.w, this.w)), 
  this;
 },
 clampScalar: function(t, e) {
  return this.x = Math.max(t, Math.min(e, this.x)), this.y = Math.max(t, Math.min(e, this.y)), 
  this.z = Math.max(t, Math.min(e, this.z)), this.w = Math.max(t, Math.min(e, this.w)), 
  this;
 },
 clampLength: function(t, e) {
  var i = this.length();
  return this.divideScalar(i || 1).multiplyScalar(Math.max(t, Math.min(e, i)));
 },
 floor: function() {
  return this.x = Math.floor(this.x), this.y = Math.floor(this.y), this.z = Math.floor(this.z), 
  this.w = Math.floor(this.w), this;
 },
 ceil: function() {
  return this.x = Math.ceil(this.x), this.y = Math.ceil(this.y), this.z = Math.ceil(this.z), 
  this.w = Math.ceil(this.w), this;
 },
 round: function() {
  return this.x = Math.round(this.x), this.y = Math.round(this.y), this.z = Math.round(this.z), 
  this.w = Math.round(this.w), this;
 },
 roundToZero: function() {
  return this.x = this.x < 0 ? Math.ceil(this.x) : Math.floor(this.x), this.y = this.y < 0 ? Math.ceil(this.y) : Math.floor(this.y), 
  this.z = this.z < 0 ? Math.ceil(this.z) : Math.floor(this.z), this.w = this.w < 0 ? Math.ceil(this.w) : Math.floor(this.w), 
  this;
 },
 negate: function() {
  return this.x = -this.x, this.y = -this.y, this.z = -this.z, this.w = -this.w, 
  this;
 },
 dot: function(t) {
  return this.x * t.x + this.y * t.y + this.z * t.z + this.w * t.w;
 },
 lengthSq: function() {
  return this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w;
 },
 length: function() {
  return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
 },
 manhattanLength: function() {
  return Math.abs(this.x) + Math.abs(this.y) + Math.abs(this.z) + Math.abs(this.w);
 },
 normalize: function() {
  return this.divideScalar(this.length() || 1);
 },
 setLength: function(t) {
  return this.normalize().multiplyScalar(t);
 },
 lerp: function(t, e) {
  return this.x += (t.x - this.x) * e, this.y += (t.y - this.y) * e, this.z += (t.z - this.z) * e, 
  this.w += (t.w - this.w) * e, this;
 },
 lerpVectors: function(t, e, i) {
  return this.subVectors(e, t).multiplyScalar(i).add(t);
 },
 equals: function(t) {
  return t.x === this.x && t.y === this.y && t.z === this.z && t.w === this.w;
 },
 fromArray: function(t, e) {
  return this.x = t[e = void 0 === e ? 0 : e], this.y = t[e + 1], this.z = t[e + 2], 
  this.w = t[e + 3], this;
 },
 toArray: function(t, e) {
  return (t = void 0 === t ? [] : t)[e = void 0 === e ? 0 : e] = this.x, t[e + 1] = this.y, 
  t[e + 2] = this.z, t[e + 3] = this.w, t;
 },
 fromBufferAttribute: function(t, e, i) {
  return void 0 !== i && console.warn("Vector4: offset has been removed from .fromBufferAttribute()."), 
  this.x = t.getX(e), this.y = t.getY(e), this.z = t.getZ(e), this.w = t.getW(e), 
  this;
 }
});

var _colorKeywords = {
 aliceblue: 15792383,
 antiquewhite: 16444375,
 aqua: 65535,
 aquamarine: 8388564,
 azure: 15794175,
 beige: 16119260,
 bisque: 16770244,
 black: 0,
 blanchedalmond: 16772045,
 blue: 255,
 blueviolet: 9055202,
 brown: 10824234,
 burlywood: 14596231,
 cadetblue: 6266528,
 chartreuse: 8388352,
 chocolate: 13789470,
 coral: 16744272,
 cornflowerblue: 6591981,
 cornsilk: 16775388,
 crimson: 14423100,
 cyan: 65535,
 darkblue: 139,
 darkcyan: 35723,
 darkgoldenrod: 12092939,
 darkgray: 11119017,
 darkgreen: 25600,
 darkgrey: 11119017,
 darkkhaki: 12433259,
 darkmagenta: 9109643,
 darkolivegreen: 5597999,
 darkorange: 16747520,
 darkorchid: 10040012,
 darkred: 9109504,
 darksalmon: 15308410,
 darkseagreen: 9419919,
 darkslateblue: 4734347,
 darkslategray: 3100495,
 darkslategrey: 3100495,
 darkturquoise: 52945,
 darkviolet: 9699539,
 deeppink: 16716947,
 deepskyblue: 49151,
 dimgray: 6908265,
 dimgrey: 6908265,
 dodgerblue: 2003199,
 firebrick: 11674146,
 floralwhite: 16775920,
 forestgreen: 2263842,
 fuchsia: 16711935,
 gainsboro: 14474460,
 ghostwhite: 16316671,
 gold: 16766720,
 goldenrod: 14329120,
 gray: 8421504,
 green: 32768,
 greenyellow: 11403055,
 grey: 8421504,
 honeydew: 15794160,
 hotpink: 16738740,
 indianred: 13458524,
 indigo: 4915330,
 ivory: 16777200,
 khaki: 15787660,
 lavender: 15132410,
 lavenderblush: 16773365,
 lawngreen: 8190976,
 lemonchiffon: 16775885,
 lightblue: 11393254,
 lightcoral: 15761536,
 lightcyan: 14745599,
 lightgoldenrodyellow: 16448210,
 lightgray: 13882323,
 lightgreen: 9498256,
 lightgrey: 13882323,
 lightpink: 16758465,
 lightsalmon: 16752762,
 lightseagreen: 2142890,
 lightskyblue: 8900346,
 lightslategray: 7833753,
 lightslategrey: 7833753,
 lightsteelblue: 11584734,
 lightyellow: 16777184,
 lime: 65280,
 limegreen: 3329330,
 linen: 16445670,
 magenta: 16711935,
 maroon: 8388608,
 mediumaquamarine: 6737322,
 mediumblue: 205,
 mediumorchid: 12211667,
 mediumpurple: 9662683,
 mediumseagreen: 3978097,
 mediumslateblue: 8087790,
 mediumspringgreen: 64154,
 mediumturquoise: 4772300,
 mediumvioletred: 13047173,
 midnightblue: 1644912,
 mintcream: 16121850,
 mistyrose: 16770273,
 moccasin: 16770229,
 navajowhite: 16768685,
 navy: 128,
 oldlace: 16643558,
 olive: 8421376,
 olivedrab: 7048739,
 orange: 16753920,
 orangered: 16729344,
 orchid: 14315734,
 palegoldenrod: 15657130,
 palegreen: 10025880,
 paleturquoise: 11529966,
 palevioletred: 14381203,
 papayawhip: 16773077,
 peachpuff: 16767673,
 peru: 13468991,
 pink: 16761035,
 plum: 14524637,
 powderblue: 11591910,
 purple: 8388736,
 rebeccapurple: 6697881,
 red: 16711680,
 rosybrown: 12357519,
 royalblue: 4286945,
 saddlebrown: 9127187,
 salmon: 16416882,
 sandybrown: 16032864,
 seagreen: 3050327,
 seashell: 16774638,
 sienna: 10506797,
 silver: 12632256,
 skyblue: 8900331,
 slateblue: 6970061,
 slategray: 7372944,
 slategrey: 7372944,
 snow: 16775930,
 springgreen: 65407,
 steelblue: 4620980,
 tan: 13808780,
 teal: 32896,
 thistle: 14204888,
 tomato: 16737095,
 turquoise: 4251856,
 violet: 15631086,
 wheat: 16113331,
 white: 16777215,
 whitesmoke: 16119285,
 yellow: 16776960,
 yellowgreen: 10145074
}, _hslA = {
 h: 0,
 s: 0,
 l: 0
}, _hslB = {
 h: 0,
 s: 0,
 l: 0
};

function Color(t, e, i) {
 return void 0 === e && void 0 === i ? this.set(t) : this.setRGB(t, e, i);
}

function hue2rgb(t, e, i) {
 return i < 0 && (i += 1), 1 < i && --i, i < 1 / 6 ? t + 6 * (e - t) * i : i < .5 ? e : i < 2 / 3 ? t + 6 * (e - t) * (2 / 3 - i) : t;
}

function SRGBToLinear(t) {
 return t < .04045 ? .0773993808 * t : Math.pow(.9478672986 * t + .0521327014, 2.4);
}

function LinearToSRGB(t) {
 return t < .0031308 ? 12.92 * t : 1.055 * Math.pow(t, .41666) - .055;
}

Object.assign(Color.prototype, {
 isColor: !0,
 r: 1,
 g: 1,
 b: 1,
 set: function(t) {
  return t && t.isColor ? this.copy(t) : "number" == typeof t ? this.setHex(t) : "string" == typeof t && this.setStyle(t), 
  this;
 },
 setScalar: function(t) {
  return this.r = t, this.g = t, this.b = t, this;
 },
 setHex: function(t) {
  return t = Math.floor(t), this.r = (t >> 16 & 255) / 255, this.g = (t >> 8 & 255) / 255, 
  this.b = (255 & t) / 255, this;
 },
 setRGB: function(t, e, i) {
  return this.r = t, this.g = e, this.b = i, this;
 },
 setHSL: function(t, e, i) {
  return t = _Math.euclideanModulo(t, 1), e = _Math.clamp(e, 0, 1), i = _Math.clamp(i, 0, 1), 
  0 === e ? this.r = this.g = this.b = i : (this.r = hue2rgb(e = 2 * i - (i = i <= .5 ? i * (1 + e) : i + e - i * e), i, t + 1 / 3), 
  this.g = hue2rgb(e, i, t), this.b = hue2rgb(e, i, t - 1 / 3)), this;
 },
 setStyle: function(e) {
  function t(t) {
   void 0 !== t && parseFloat(t) < 1 && console.warn("Color: Alpha component of " + e + " will be ignored.");
  }
  if (h = /^((?:rgb|hsl)a?)\(\s*([^\)]*)\)/.exec(e)) {
   var i, r, s, a, n = h[1], o = h[2];
   switch (n) {
   case "rgb":
   case "rgba":
    if (i = /^(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*(,\s*([0-9]*\.?[0-9]+)\s*)?$/.exec(o)) return this.r = Math.min(255, parseInt(i[1], 10)) / 255, 
    this.g = Math.min(255, parseInt(i[2], 10)) / 255, this.b = Math.min(255, parseInt(i[3], 10)) / 255, 
    t(i[5]), this;
    if (i = /^(\d+)\%\s*,\s*(\d+)\%\s*,\s*(\d+)\%\s*(,\s*([0-9]*\.?[0-9]+)\s*)?$/.exec(o)) return this.r = Math.min(100, parseInt(i[1], 10)) / 100, 
    this.g = Math.min(100, parseInt(i[2], 10)) / 100, this.b = Math.min(100, parseInt(i[3], 10)) / 100, 
    t(i[5]), this;
    break;

   case "hsl":
   case "hsla":
    if (i = /^([0-9]*\.?[0-9]+)\s*,\s*(\d+)\%\s*,\s*(\d+)\%\s*(,\s*([0-9]*\.?[0-9]+)\s*)?$/.exec(o)) return r = parseFloat(i[1]) / 360, 
    s = parseInt(i[2], 10) / 100, a = parseInt(i[3], 10) / 100, t(i[5]), this.setHSL(r, s, a);
   }
  } else if (h = /^\#([A-Fa-f0-9]+)$/.exec(e)) {
   var n = h[1], h = n.length;
   if (3 === h) return this.r = parseInt(n.charAt(0) + n.charAt(0), 16) / 255, this.g = parseInt(n.charAt(1) + n.charAt(1), 16) / 255, 
   this.b = parseInt(n.charAt(2) + n.charAt(2), 16) / 255, this;
   if (6 === h) return this.r = parseInt(n.charAt(0) + n.charAt(1), 16) / 255, this.g = parseInt(n.charAt(2) + n.charAt(3), 16) / 255, 
   this.b = parseInt(n.charAt(4) + n.charAt(5), 16) / 255, this;
  }
  return e && 0 < e.length ? this.setColorName(e) : this;
 },
 setColorName: function(t) {
  var e = _colorKeywords[t];
  return void 0 !== e ? this.setHex(e) : console.warn("Color: Unknown color " + t), 
  this;
 },
 clone: function() {
  return new this.constructor(this.r, this.g, this.b);
 },
 copy: function(t) {
  return this.r = t.r, this.g = t.g, this.b = t.b, this;
 },
 copyGammaToLinear: function(t, e) {
  return void 0 === e && (e = 2), this.r = Math.pow(t.r, e), this.g = Math.pow(t.g, e), 
  this.b = Math.pow(t.b, e), this;
 },
 copyLinearToGamma: function(t, e) {
  e = 0 < (e = void 0 === e ? 2 : e) ? 1 / e : 1;
  return this.r = Math.pow(t.r, e), this.g = Math.pow(t.g, e), this.b = Math.pow(t.b, e), 
  this;
 },
 convertGammaToLinear: function(t) {
  return this.copyGammaToLinear(this, t), this;
 },
 convertLinearToGamma: function(t) {
  return this.copyLinearToGamma(this, t), this;
 },
 copySRGBToLinear: function(t) {
  return this.r = SRGBToLinear(t.r), this.g = SRGBToLinear(t.g), this.b = SRGBToLinear(t.b), 
  this;
 },
 copyLinearToSRGB: function(t) {
  return this.r = LinearToSRGB(t.r), this.g = LinearToSRGB(t.g), this.b = LinearToSRGB(t.b), 
  this;
 },
 convertSRGBToLinear: function() {
  return this.copySRGBToLinear(this), this;
 },
 convertLinearToSRGB: function() {
  return this.copyLinearToSRGB(this), this;
 },
 getHex: function() {
  return 255 * this.r << 16 ^ 255 * this.g << 8 ^ 255 * this.b << 0;
 },
 getHexString: function() {
  return ("000000" + this.getHex().toString(16)).slice(-6);
 },
 getHSL: function(t) {
  void 0 === t && (console.warn("Color: .getHSL() target is now required"), t = {
   h: 0,
   s: 0,
   l: 0
  });
  var e, i = this.r, r = this.g, s = this.b, a = Math.max(i, r, s), n = Math.min(i, r, s), o = (n + a) / 2;
  if (n === a) u = e = 0; else {
   var h = a - n, u = o <= .5 ? h / (a + n) : h / (2 - a - n);
   switch (a) {
   case i:
    e = (r - s) / h + (r < s ? 6 : 0);
    break;

   case r:
    e = (s - i) / h + 2;
    break;

   case s:
    e = (i - r) / h + 4;
   }
   e /= 6;
  }
  return t.h = e, t.s = u, t.l = o, t;
 },
 getStyle: function() {
  return "rgb(" + (255 * this.r | 0) + "," + (255 * this.g | 0) + "," + (255 * this.b | 0) + ")";
 },
 offsetHSL: function(t, e, i) {
  return this.getHSL(_hslA), _hslA.h += t, _hslA.s += e, _hslA.l += i, this.setHSL(_hslA.h, _hslA.s, _hslA.l), 
  this;
 },
 add: function(t) {
  return this.r += t.r, this.g += t.g, this.b += t.b, this;
 },
 addColors: function(t, e) {
  return this.r = t.r + e.r, this.g = t.g + e.g, this.b = t.b + e.b, this;
 },
 addScalar: function(t) {
  return this.r += t, this.g += t, this.b += t, this;
 },
 sub: function(t) {
  return this.r = Math.max(0, this.r - t.r), this.g = Math.max(0, this.g - t.g), 
  this.b = Math.max(0, this.b - t.b), this;
 },
 multiply: function(t) {
  return this.r *= t.r, this.g *= t.g, this.b *= t.b, this;
 },
 multiplyScalar: function(t) {
  return this.r *= t, this.g *= t, this.b *= t, this;
 },
 lerp: function(t, e) {
  return this.r += (t.r - this.r) * e, this.g += (t.g - this.g) * e, this.b += (t.b - this.b) * e, 
  this;
 },
 lerpHSL: function(t, e) {
  this.getHSL(_hslA), t.getHSL(_hslB);
  var t = _Math.lerp(_hslA.h, _hslB.h, e), i = _Math.lerp(_hslA.s, _hslB.s, e), e = _Math.lerp(_hslA.l, _hslB.l, e);
  return this.setHSL(t, i, e), this;
 },
 equals: function(t) {
  return t.r === this.r && t.g === this.g && t.b === this.b;
 },
 fromArray: function(t, e) {
  return this.r = t[e = void 0 === e ? 0 : e], this.g = t[e + 1], this.b = t[e + 2], 
  this;
 },
 toArray: function(t, e) {
  return (t = void 0 === t ? [] : t)[e = void 0 === e ? 0 : e] = this.r, t[e + 1] = this.g, 
  t[e + 2] = this.b, t;
 },
 toJSON: function() {
  return this.getHex();
 }
}), Color.NAMES = _colorKeywords;

var Cache = {
 enabled: !1,
 files: {},
 add: function(t, e) {
  !1 !== this.enabled && (this.files[t] = e);
 },
 get: function(t) {
  if (!1 !== this.enabled) return this.files[t];
 },
 remove: function(t) {
  delete this.files[t];
 },
 clear: function() {
  this.files = {};
 }
}, ImageCache = {
 cached: new Map(),
 incoming: new Map(),
 verbose: !1,
 deliver: function(e, i) {
  this.verbose && console.log("ImageCache deliver", this.cacheid, e);
  var t = this.cached.get(e);
  if (void 0 !== t) this.verbose && console.log("ImageCache HAS", e), i(e, t, !1); else {
   t = this.incoming.get(e);
   if (void 0 !== t) this.verbose && console.log("ImageCache EXPECTING", e), t.push(i); else {
    this.verbose && console.log("ImageCache does NOT HAVE -- requesting", e), this.incoming.set(e, [ i ]);
    let t = new Image();
    t.onload = () => {
     this.image_loaded(e, t);
    }, t.onerror = () => {
     this.image_loaded(e, null);
    }, t.src = e;
   }
  }
 },
 image_loaded: function(e, i) {
  i ? this.verbose && console.log("ImageCache image_loaded success", e) : console.error("ImageCache image_loaded error loading", e), 
  this.cached.set(e, i);
  var r = this.incoming.get(e);
  for (let t = 0; t < r.length; ++t) r[t](e, i, !0);
  this.incoming.delete(e);
 },
 remove: function(t) {
  this.cached.delete(t);
 },
 clear: function() {
  this.cached.clear();
 }
};

class TextureCache {
 constructor() {
  this.tex_cache = new Map(), this.tex_precache = new Map(), this.verbose = !1;
 }
 deliver(t, e, i, r) {
  var s = this.tex_cache.get(t);
  void 0 !== s ? (this.verbose && console.log("TextureCache HAS", t), s && e(s)) : void 0 !== (s = this.tex_precache.get(t)) ? (this.verbose && console.log("TextureCache url is incoming -- appending callback", t), 
  s.array.push(e)) : (this.tex_precache.set(t, {
   img2tex: i,
   delayed: r,
   array: [ e ]
  }), ImageCache.deliver(t, this.image_loaded.bind(this)));
 }
 image_loaded(t, e, i) {
  var r = this.tex_precache.get(t), s = e ? r.img2tex(e) : null;
  if (this.tex_cache.set(t, s), s) for (let t = 0; t < r.array.length; ++t) r.array[t](s);
  s && i && r.delayed(), this.tex_precache.delete(t);
 }
 remove(t) {
  this.tex_cache.delete(t);
 }
 clear() {
  this.tex_cache.clear();
 }
}

class LoadingManager {
 constructor(t, e, i) {
  var r = this, s = !1, a = 0, n = 0;
  this.onStart = void 0, this.onLoad = t, this.onProgress = e, this.onError = i, 
  this.itemStart = function(t) {
   n++, !1 === s && void 0 !== r.onStart && r.onStart(t, a, n), s = !0;
  }, this.itemEnd = function(t) {
   a++, void 0 !== r.onProgress && r.onProgress(t, a, n), a === n && (s = !1, void 0 !== r.onLoad) && r.onLoad(t, a, n);
  }, this.itemError = function(t) {
   void 0 !== r.onError && r.onError(t);
  };
 }
}

class XHRLoader {
 constructor(t = new LoadingManager(), e = "") {
  this.manager = t, this.responseType = e;
 }
 load(i, r, e, s) {
  void 0 !== this.path && (i = this.path + i);
  var t, a = this, n = Cache.get(i);
  return void 0 !== n ? (r && setTimeout(function() {
   r(n);
  }, 0), n) : ((t = new XMLHttpRequest()).overrideMimeType("text/plain"), t.responseType = this.responseType, 
  t.open("GET", i, !0), t.addEventListener("load", function(t) {
   var e = t.target.response;
   Cache.add(i, e), 200 === this.status || 0 === this.status ? (r && r(e), a.manager.itemEnd(i)) : (s && s(t), 
   a.manager.itemError(i));
  }, !1), void 0 !== e && t.addEventListener("progress", function(t) {
   e(t);
  }, !1), t.addEventListener("error", function(t) {
   s && s(t), a.manager.itemError(i);
  }, !1), void 0 !== this.responseType && (t.responseType = this.responseType), 
  void 0 !== this.withCredentials && (t.withCredentials = this.withCredentials), 
  t.send(null), a.manager.itemStart(i), t);
 }
 setPath(t) {
  this.path = t;
 }
 setResponseType(t) {
  this.responseType = t;
 }
 setWithCredentials(t) {
  this.withCredentials = t;
 }
 extractUrlBase(t) {
  t = t.split("/");
  return 1 === t.length ? "./" : (t.pop(), t.join("/") + "/");
 }
}

class ShaderLoader {
 static sAllPrograms = new Set();
 constructor(t = new LoadingManager(), e) {
  this._xhrLoader = new XHRLoader(t), this._pending_urls = [], this._programs = {}, 
  this._executor = this.executor, this._queue = [], this._inProgress = !1;
 }
 addUrls(...t) {
  for (var e = 0; e < t.length; e++) "/" !== t[e].slice(-1) && (t[e] += "/");
  this._pending_urls = [ ...new Set([].concat(this._pending_urls, t)) ];
 }
 loadProgramList(h, u, e) {
  var l = this;
  this._executor(function(s) {
   const a = l._pending_urls.length;
   for (var n = 0, t = 0; t < a; t++) {
    const o = l._pending_urls[t];
    l._xhrLoader.load(o + "programs.json", function(t) {
     var e, i = JSON.parse(t);
     for (e in i) {
      var r = l._programs[e];
      void 0 === r && (r = i[e], l._programs[e] = r), void 0 === r.urls ? r.urls = [ o ] : r.urls.push(o);
     }
     n++, void 0 !== u && (t = new ProgressEvent("ProgramListLoaded", {
      lengthComputable: !0,
      loaded: n,
      total: a
     }), u(t)), a === n && (void 0 !== h && h(l._programs), s());
    }, void 0, function(t) {
     n++, void 0 !== e && e(t), void 0 !== u && (t = new ProgressEvent("ProgramListLoaded", {
      lengthComputable: !0,
      loaded: n,
      total: a
     }), u(t)), a === n && (void 0 !== h && h(l._programs), s());
    });
   }
   l._pending_urls = [];
  });
 }
 loadProgramSources(l, _, c, d) {
  0 < this._pending_urls.length && this.loadProgramList();
  var m = this;
  this._executor(function(i) {
   var t = m._programs[l];
   if (void 0 === t) d(), i(); else {
    var e = t.shaders, r = Object.keys(e), s = 0;
    const h = r.length;
    for (var a = {
     sources: {}
    }, n = 0; n < r.length; n++) {
     const u = r[n];
     var o = t.urls[0] + e[u];
     m._xhrLoader.load(o, function(t) {
      var e;
      s++, ShaderLoader.sAllPrograms.add(l), void 0 !== c && (e = new ProgressEvent("ShaderSourceLoaded", {
       lengthComputable: !0,
       loaded: s,
       total: h
      }), c(e)), a.id = l, a.sources[u] = t, s === h && (void 0 !== _ && _(a), i());
     }, void 0, function(t) {
      var e;
      s++, void 0 !== c && (e = new ProgressEvent("ShaderSourceLoaded", {
       lengthComputable: !0,
       loaded: s,
       total: h
      }), c(e)), void 0 !== d && d(t), s === h && (void 0 !== _ && _(programSources), 
      i());
     });
    }
   }
  });
 }
 loadMultipleProgramSources(t, i, r, s) {
  var a = 0;
  const n = t.length;
  for (var o = [], e = function(t) {
   a++, o.push(t), void 0 !== r && (t = new ProgressEvent("ProgramSourcesLoaded", {
    lengthComputable: !0,
    loaded: a,
    total: n
   }), r(t)), void 0 !== i && a === n && i(o);
  }, h = function(t) {
   var e;
   a++, void 0 !== r && (e = new ProgressEvent("ProgramSourcesLoaded", {
    lengthComputable: !0,
    loaded: a,
    total: n
   }), r(e)), null != s && s(t), void 0 !== i && a === n && i(o);
  }, u = 0; u < n; u++) this.loadProgramSources(t[u], e, void 0, h);
 }
 get programList() {
  return Object.keys(this._programs);
 }
 resolvePrograms(t, e = !0) {
  var i, r = {};
  for (i of t) {
   var s = structuredClone(this._programs[i]);
   e && delete s.urls, r[i] = s;
  }
  return r;
 }
 executor(t, ...e) {
  const i = this;
  var r;
  this._queue.push({
   exec: t,
   args: e
  }), !1 === this._inProgress && (this._inProgress = !0, (r = function() {
   var t;
   0 < i._queue.length ? (t = i._queue.shift()).exec(r, t.args) : i._inProgress = !1;
  })());
 }
}

class ImageLoader {
 constructor(t) {
  this.manager = t || new LoadingManager();
 }
 load(e, i, r, s) {
  var a = this, t = (void 0 !== this.path && (e = this.path + e), this.manager.itemStart(e), 
  Cache.get(e));
  if (void 0 !== t) return i ? setTimeout(function() {
   i(t), a.manager.itemEnd(e);
  }, 0) : a.manager.itemEnd(e), t;
  var n = new Image();
  n.src = e, n.addEventListener("load", function(t) {
   Cache.add(e, this), void 0 !== i && i(n), a.manager.itemEnd(e);
  }), n.addEventListener("progress", function(t) {
   void 0 !== r && r(t);
  }), n.addEventListener("error", function(t) {
   s && s(t), a.manager.itemError(e);
  }), void 0 !== this.crossOrigin && (n.crossOrigin = this.crossOrigin);
 }
 setCrossOrigin(t) {
  this.crossOrigin = t;
 }
 setPath(t) {
  this.path = t;
 }
}

class UpdateListener {
 constructor(t, e, i, r) {
  this._onObjectUpdate = t || function() {}, this._onHierarchyUpdate = e || function() {}, 
  this._onMaterialUpdate = i || function() {}, this._onGeometryUpdate = r || function() {};
 }
 get objectUpdate() {
  return this._onObjectUpdate;
 }
 get hierarchyUpdate() {
  return this._onHierarchyUpdate;
 }
 get materialUpdate() {
  return this._onMaterialUpdate;
 }
 get geometryUpdate() {
  return this._onGeometryUpdate;
 }
 set objectUpdate(t) {
  this._onObjectUpdate = t;
 }
 set hierarchyUpdate(t) {
  this._onHierarchyUpdate = t;
 }
 set materialUpdate(t) {
  this._onMaterialUpdate = t;
 }
 set geometryUpdate(t) {
  this._onGeometryUpdate = t;
 }
}

class BufferAttribute {
 static TARGET = {
  ARRAY_BUFFER: 0,
  ELEMENT_ARRAY_BUFFER: 1,
  COPY_READ_BUFFER: 2,
  COPY_WRITE_BUFFER: 3,
  TRANSFORM_FEEDBACK_BUFFER: 4,
  UNIFORM_BUFFER: 5,
  PIXEL_PACK_BUFFER: 6,
  PIXEL_UNPACK_BUFFER: 7
 };
 static DRAW_TYPE = {
  STATIC: 0,
  STREAMING: 1,
  DYNAMIC: 2
 };
 constructor(t, e, i = 0, r = {}) {
  this._array = t, this._itemSize = e, this._divisor = i, this._dirty = !0, this._drawType = BufferAttribute.DRAW_TYPE.STATIC, 
  this._update = !1, this.target = void 0 !== r.target ? r.target : BufferAttribute.TARGET.ARRAY_BUFFER, 
  this.idleTime = 0, this._locations = new Array();
 }
 count() {
  return this._array.length / this._itemSize;
 }
 set array(t) {
  this._array.length == t.length ? this._update = !0 : this._dirty = !0, this._array = t;
 }
 set itemSize(t) {
  this._itemSize = t, this._dirty = !0;
 }
 set dirty(t) {
  this._dirty = t;
 }
 set drawType(t) {
  this._drawType = t;
 }
 get array() {
  return this._array;
 }
 get itemSize() {
  return this._itemSize;
 }
 get size() {
  return this.array.byteLength;
 }
 get dirty() {
  return this._dirty;
 }
 get update() {
  return this._update;
 }
 set update(t) {
  this._update = t;
 }
 get divisor() {
  return this._divisor;
 }
 set divisor(t) {
  this._divisor = t;
 }
 get drawType() {
  return this._drawType;
 }
 get target() {
  return this._target;
 }
 set target(t) {
  this._target = t;
 }
 get locations() {
  return this._locations;
 }
 set locations(t) {
  this._locations = t;
 }
 update() {
  this._update = !0;
 }
}

function Int8Attribute(t, e, i = 0) {
 return new BufferAttribute(new Int8Array(t), e, i);
}

function Uint8Attribute(t, e, i = 0) {
 return new BufferAttribute(new Uint8Array(t), e, i);
}

function Uint8ClampedAttribute(t, e, i = 0) {
 return new BufferAttribute(new Uint8ClampedArray(t), e, i);
}

function Int16Attribute(t, e, i = 0) {
 return new BufferAttribute(new Int16Array(t), e, i);
}

function Uint16Attribute(t, e, i = 0) {
 return new BufferAttribute(new Uint16Array(t), e, i);
}

function Int32Attribute(t, e, i = 0) {
 return new BufferAttribute(new Int32Array(t), e, i);
}

function Uint32Attribute(t, e, i = 0) {
 return new BufferAttribute(new Uint32Array(t), e, i);
}

function Float32Attribute(t, e, i = 0) {
 return new BufferAttribute(new Float32Array(t), e, i);
}

function Float64Attribute(t, e, i = 0) {
 return new BufferAttribute(new Float64Array(t), e, i);
}

class GLAttributeManager {
 constructor(t) {
  this._gl = t, this._cached_buffers = new Map(), this.DRAW_TYPE = new Map([ [ BufferAttribute.DRAW_TYPE.STATIC, t.STATIC_DRAW ], [ BufferAttribute.DRAW_TYPE.STREAMING, t.STREAM_DRAW ], [ BufferAttribute.DRAW_TYPE.DYNAMIC, t.DYNAMIC_DRAW ] ]), 
  this.TARGET = new Map([ [ BufferAttribute.TARGET.ARRAY_BUFFER, t.ARRAY_BUFFER ], [ BufferAttribute.TARGET.ELEMENT_ARRAY_BUFFER, t.ELEMENT_ARRAY_BUFFER ], [ BufferAttribute.TARGET.COPY_READ_BUFFER, t.COPY_READ_BUFFER ], [ BufferAttribute.TARGET.COPY_WRITE_BUFFER, t.COPY_WRITE_BUFFER ], [ BufferAttribute.TARGET.TRANSFORM_FEEDBACK_BUFFER, t.TRANSFORM_FEEDBACK_BUFFER ], [ BufferAttribute.TARGET.UNIFORM_BUFFER, t.UNIFORM_BUFFER ], [ BufferAttribute.TARGET.PIXEL_PACK_BUFFER, t.PIXEL_PACK_BUFFER ], [ BufferAttribute.TARGET.PIXEL_UNPACK_BUFFER, t.PIXEL_UNPACK_BUFFER ] ]);
 }
 _createGLBuffer(t) {
  var e = t.target ? this.TARGET.get(t.target) : this._gl.ARRAY_BUFFER, i = t.size, r = this.DRAW_TYPE.get(t.drawType), s = this._gl.createBuffer();
  return this._gl.bindBuffer(e, s), this._gl.bufferData(e, i, r), this._gl.bindBuffer(e, null), 
  this._cached_buffers.set(t, s), s;
 }
 _updateAttribute(t) {
  var e = this._cached_buffers.get(t), i = t.target ? this.TARGET.get(t.target) : this._gl.ARRAY_BUFFER;
  (t.dirty || t._update) && (this._gl.bindBuffer(i, e), t.dirty && (e = this.DRAW_TYPE.get(t.drawType), 
  this._gl.bufferData(i, t.size, e), t.dirty = !1), this._gl.bufferSubData(i, 0, t.array, 0, 0), 
  this._gl.bindBuffer(i, null), t._update = !1);
 }
 getGLBuffer(t) {
  var e;
  return t.idleTime = 0, this._cached_buffers.has(t) ? (e = this._cached_buffers.get(t), 
  (t.dirty || t._update) && this._updateAttribute(t), e) : (e = this._createGLBuffer(t), 
  (t.dirty || t._update) && this._updateAttribute(t), e);
 }
 deleteBuffer(e, t) {
  e.dirty = !0, this._cached_buffers.delete(e), this._gl.deleteBuffer(t);
  for (let t = 0; t < e.locations.length; t++) {
   var i = e.locations[t];
   this._gl.disableVertexAttribArray(i);
  }
  e.locations = new Array();
 }
 deleteBuffers(t = !1, e = 1e3) {
  if (t) for (var [ i, r ] of this._cached_buffers) i.idleTime >= e && this.deleteBuffer(i, r); else for (var [ s, a ] of this._cached_buffers) this.deleteBuffer(s, a);
 }
 incrementTime() {
  for (var [ t, e ] of this._cached_buffers) t.idleTime = t.idleTime + 1;
 }
}

class GLFrameBufferManager {
 constructor(t) {
  this._gl = t, this._cached_fbos = new Map();
 }
 bindFramebuffer(t) {
  var e = this._cached_fbos.get(t);
  void 0 === e && (e = this._gl.createFramebuffer(), this._cached_fbos.set(t, e)), 
  this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, e);
 }
 unbindFramebuffer() {
  this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, null);
 }
 deleteFrameBuffer(t, e) {
  this._cached_fbos.delete(t), this._gl.deleteFramebuffer(e);
 }
 deleteFrameBuffers() {
  for (var [ t, e ] of this._cached_fbos) this.deleteFrameBuffer(t, e);
 }
}

class Texture {
 static DEFAULT_IMAGE = null;
 static FILTER = {
  NearestFilter: 0,
  NearestMipMapNearestFilter: 1,
  NearestMipMapLinearFilter: 2,
  LinearFilter: 3,
  LinearMipMapNearestFilter: 4,
  LinearMipMapLinearFilter: 5
 };
 static FORMAT = {
  ALPHA: 6,
  RGB: 7,
  RGBA: 8,
  LUMINANCE: 9,
  LUMINANCE_ALPHA: 10,
  DEPTH_COMPONENT: 11,
  DEPTH_COMPONENT24: 12,
  DEPTH_COMPONENT32F: 12.5,
  RGB16F: 13,
  RGB32F: 14,
  RGBA16F: 15,
  RGBA32F: 16,
  R16F: 17,
  R8: 17.1,
  RED: 17.2,
  RED_INTEGER: 17.25,
  R32F: 17.3,
  R32I: 17.4,
  R32UI: 17.5
 };
 static WRAPPING = {
  RepeatWrapping: 18,
  ClampToEdgeWrapping: 19,
  MirroredRepeatWrapping: 20
 };
 static TYPE = {
  UNSIGNED_BYTE: 21,
  UNSIGNED_SHORT: 22,
  UNSIGNED_INT: 23,
  HALF_FLOAT: 24,
  FLOAT: 25,
  INT: 26
 };
 _update = {
  size: !0
 };
 constructor(t, e, i, r, s, a, n, o, h = 1024, u = 1024) {
  this._uuid = _Math.generateUUID(), this.type = "Texture", this._image = t || Texture.DEFAULT_IMAGE, 
  this._magFilter = void 0 !== s ? s : Texture.FILTER.LinearFilter, this._minFilter = void 0 !== r ? r : Texture.FILTER.LinearFilter, 
  this._wrapS = void 0 !== e ? e : Texture.WRAPPING.ClampToEdgeWrapping, this._wrapT = void 0 !== i ? i : Texture.WRAPPING.ClampToEdgeWrapping, 
  this._internalFormat = void 0 !== a ? a : Texture.FORMAT.RGBA, this._format = void 0 !== n ? n : Texture.FORMAT.RGBA, 
  this._type = void 0 !== o ? o : Texture.TYPE.UNSIGNED_BYTE, this.clearFunction = 0, 
  this._generateMipmaps = !1, this._width = h, this._height = u, this._flipy = !0, 
  this._dirty = !0, this.update = {
   size: !0
  }, this.idleTime = 0;
 }
 applyConfig(t) {
  this.wrapS = t.wrapS, this.wrapT = t.wrapT, this.minFilter = t.minFilter, this.magFilter = t.magFilter, 
  this.internalFormat = t.internalFormat, this.format = t.format, this.type = t.type, 
  this.clearFunction = t.clearFunction;
 }
 get dirty() {
  return this._dirty;
 }
 set dirty(t) {
  this._dirty = t;
 }
 get update() {
  return this._update;
 }
 set update(t) {
  this._update = t;
 }
 get image() {
  return this._image;
 }
 get wrapS() {
  return this._wrapS;
 }
 get wrapT() {
  return this._wrapT;
 }
 get minFilter() {
  return this._minFilter;
 }
 get magFilter() {
  return this._magFilter;
 }
 get internalFormat() {
  return this._internalFormat;
 }
 get format() {
  return this._format;
 }
 get type() {
  return this._type;
 }
 get width() {
  return this._width;
 }
 get height() {
  return this._height;
 }
 get flipy() {
  return this._flipy;
 }
 set image(t) {
  t !== this._image && (this._image = t, this._dirty = !0);
 }
 set wrapS(t) {
  t !== this._wrapS && (this._wrapS = t, this._dirty = !0);
 }
 set wrapT(t) {
  t !== this._wrapT && (this._wrapT = t, this._dirty = !0);
 }
 set minFilter(t) {
  t !== this._minFilter && (this._minFilter = t, this._dirty = !0);
 }
 set magFilter(t) {
  t !== this._magFilter && (this._magFilter = t, this._dirty = !0);
 }
 set internalFormat(t) {
  t !== this._internalFormat && (this._internalFormat = t, this._dirty = !0);
 }
 set format(t) {
  t !== this._format && (this._format = t, this._dirty = !0);
 }
 set width(t) {
  t !== this._width && (this._width = t, this._dirty = !0, this.update.size = !0);
 }
 set height(t) {
  t !== this._height && (this._height = t, this._dirty = !0, this.update.size = !0);
 }
 set flipy(t) {
  t !== this._flipy && (this._flipy = t, this._dirty = !0);
 }
 set type(t) {
  t !== this._type && (this._type = t, this._dirty = !0);
 }
}

class GLTextureManager {
 _activeTexture;
 constructor(t) {
  this._gl = t, this._cached_textures = new Map(), this._colorClearFramebuffer = this._gl.createFramebuffer(), 
  this.activeTexture = 0;
 }
 get activeTexture() {
  return this._activeTexture;
 }
 set activeTexture(t) {
  this._activeTexture = t, this._gl.activeTexture(this._gl.TEXTURE0 + t);
 }
 _createGLTexture(t) {
  var e = this._formatToGL(t._internalFormat), i = this._formatToGL(t._format), r = (this._magFilterToGL(t._magFilter), 
  this._minFilterToGL(t._minFilter), this._wrapToGL(t._wrapS), this._wrapToGL(t._wrapT), 
  this._typeToGL(t._type)), s = t._width, a = t._height, n = this._gl.createTexture();
  return this._gl.activeTexture(this._gl.TEXTURE0 + this._gl.getParameter(this._gl.MAX_COMBINED_TEXTURE_IMAGE_UNITS) - 1), 
  this._gl.bindTexture(this._gl.TEXTURE_2D, n), this._gl.texImage2D(this._gl.TEXTURE_2D, 0, e, s, a, 0, i, r, null), 
  this._gl.bindTexture(this._gl.TEXTURE_2D, null), this._cached_textures.set(t, n), 
  n;
 }
 _updateTexture(t) {
  var e = this._cached_textures.get(t), i = this._formatToGL(t._internalFormat), r = this._formatToGL(t._format), s = this._magFilterToGL(t._magFilter), a = this._minFilterToGL(t._minFilter), n = this._wrapToGL(t._wrapS), o = this._wrapToGL(t._wrapT), h = this._typeToGL(t._type), u = t._width, l = t._height;
  this._gl.activeTexture(this._gl.TEXTURE0 + this._gl.getParameter(this._gl.MAX_COMBINED_TEXTURE_IMAGE_UNITS) - 1), 
  this._gl.bindTexture(this._gl.TEXTURE_2D, e), t.update.size && (this._gl.texImage2D(this._gl.TEXTURE_2D, 0, i, u, l, 0, r, h, null), 
  t.update.size = !1), t.image && (this._gl.pixelStorei(this._gl.UNPACK_FLIP_Y_WEBGL, t.flipy), 
  this._gl.texSubImage2D(this._gl.TEXTURE_2D, 0, 0, 0, u, l, r, h, t.image), this._gl.pixelStorei(this._gl.UNPACK_FLIP_Y_WEBGL, !1)), 
  this._gl.texParameteri(this._gl.TEXTURE_2D, this._gl.TEXTURE_MAG_FILTER, s), this._gl.texParameteri(this._gl.TEXTURE_2D, this._gl.TEXTURE_MIN_FILTER, a), 
  this._gl.texParameteri(this._gl.TEXTURE_2D, this._gl.TEXTURE_WRAP_S, n), this._gl.texParameteri(this._gl.TEXTURE_2D, this._gl.TEXTURE_WRAP_T, o), 
  t._generateMipmaps && this._gl.generateMipmap(this._gl.TEXTURE_2D), this._gl.bindTexture(this._gl.TEXTURE_2D, null), 
  t.dirty = !1;
 }
 _createGLCubeTexture(t) {
  var e = this._formatToGL(t._internalFormat), i = this._formatToGL(t._format), r = (this._magFilterToGL(t._magFilter), 
  this._minFilterToGL(t._minFilter), this._wrapToGL(t._wrapS), this._wrapToGL(t._wrapT), 
  this._wrapToGL(t._wrapR), this._typeToGL(t._type)), s = t._width, a = t._height, s = Math.min(s, a), a = this._gl.createTexture();
  return this._gl.activeTexture(this._gl.TEXTURE0 + this._gl.getParameter(this._gl.MAX_COMBINED_TEXTURE_IMAGE_UNITS) - 1), 
  this._gl.bindTexture(this._gl.TEXTURE_CUBE_MAP, a), this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_X, 0, e, s, s, 0, i, r, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_X, 0, e, s, s, 0, i, r, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_Y, 0, e, s, s, 0, i, r, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, e, s, s, 0, i, r, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_Z, 0, e, s, s, 0, i, r, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, e, s, s, 0, i, r, null), 
  this._gl.bindTexture(this._gl.TEXTURE_CUBE_MAP, null), this._cached_textures.set(t, a), 
  a;
 }
 _updateCubeTexture(t) {
  var e = this._cached_textures.get(t), i = this._formatToGL(t._internalFormat), r = this._formatToGL(t._format), s = this._magFilterToGL(t._magFilter), a = this._minFilterToGL(t._minFilter), n = this._wrapToGL(t._wrapS), o = this._wrapToGL(t._wrapT), h = this._wrapToGL(t._wrapR), u = this._typeToGL(t._type), l = t._width, _ = t._height, l = Math.min(l, _);
  this._gl.activeTexture(this._gl.TEXTURE0 + this._gl.getParameter(this._gl.MAX_COMBINED_TEXTURE_IMAGE_UNITS) - 1), 
  this._gl.bindTexture(this._gl.TEXTURE_CUBE_MAP, e), t.update.size && (this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_X, 0, i, l, l, 0, r, u, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_X, 0, i, l, l, 0, r, u, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_Y, 0, i, l, l, 0, r, u, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, i, l, l, 0, r, u, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_Z, 0, i, l, l, 0, r, u, null), 
  this._gl.texImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, i, l, l, 0, r, u, null), 
  t.update.size = !1), this._gl.pixelStorei(this._gl.UNPACK_FLIP_Y_WEBGL, t.flipy), 
  t.images.right && this._gl.texSubImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_X, 0, 0, 0, l, l, r, u, t.images.right), 
  t.images.left && this._gl.texSubImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_X, 0, 0, 0, l, l, r, u, t.images.left), 
  t.images.top && this._gl.texSubImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_Y, 0, 0, 0, l, l, r, u, t.images.top), 
  t.images.bottom && this._gl.texSubImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, 0, 0, l, l, r, u, t.images.bottom), 
  t.images.front && this._gl.texSubImage2D(this._gl.TEXTURE_CUBE_MAP_POSITIVE_Z, 0, 0, 0, l, l, r, u, t.images.front), 
  t.images.back && this._gl.texSubImage2D(this._gl.TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, 0, 0, l, l, r, u, t.images.back), 
  this._gl.pixelStorei(this._gl.UNPACK_FLIP_Y_WEBGL, !1), this._gl.texParameteri(this._gl.TEXTURE_CUBE_MAP, this._gl.TEXTURE_MAG_FILTER, s), 
  this._gl.texParameteri(this._gl.TEXTURE_CUBE_MAP, this._gl.TEXTURE_MIN_FILTER, a), 
  this._gl.texParameteri(this._gl.TEXTURE_CUBE_MAP, this._gl.TEXTURE_WRAP_S, n), 
  this._gl.texParameteri(this._gl.TEXTURE_CUBE_MAP, this._gl.TEXTURE_WRAP_T, o), 
  this._gl.texParameteri(this._gl.TEXTURE_CUBE_MAP, this._gl.TEXTURE_WRAP_R, h), 
  t._generateMipmaps && this._gl.generateMipmap(this._gl.TEXTURE_CUBE_MAP), this._gl.bindTexture(this._gl.TEXTURE_CUBE_MAP, null), 
  t.dirty = !1;
 }
 getGLTexture(t) {
  var e;
  return t.idleTime = 0, this._cached_textures.has(t) ? (e = this._cached_textures.get(t), 
  t.dirty && this._updateTexture(t), e) : (e = this._createGLTexture(t), t.dirty && this._updateTexture(t), 
  e);
 }
 getGLCubeTexture(t) {
  var e;
  return t.idleTime = 0, this._cached_textures.has(t) ? (e = this._cached_textures.get(t), 
  t.dirty && this._updateCubeTexture(t), e) : (e = this._createGLCubeTexture(t), 
  t.dirty && this._updateCubeTexture(t), e);
 }
 clearBoundTexture() {
  var t = this._gl.getParameter(this._gl.DRAW_FRAMEBUFFER_BINDING), e = this._gl.getParameter(this._gl.COLOR_CLEAR_VALUE);
  this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, this._colorClearFramebuffer), this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.COLOR_ATTACHMENT0, this._gl.TEXTURE_2D, glTexture, 0), 
  this._gl.drawBuffers([ this._gl.COLOR_ATTACHMENT0 ]), this._gl.clearColor(0, 0, 0, 0), 
  this._gl.clear(this._gl.COLOR_BUFFER_BIT), this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.COLOR_ATTACHMENT0, this._gl.TEXTURE_2D, null, 0), 
  this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, t), this._gl.clearColor(e[0], e[1], e[2], e[3]);
 }
 deleteTexture(t, e) {
  t.dirty = !0, this._cached_textures.delete(t), this._gl.deleteTexture(e);
 }
 deleteTextures(t = !1, e = 1e3) {
  if (t) for (var [ i, r ] of this._cached_textures) i.idleTime >= e && this.deleteTexture(i, r); else for (var [ s, a ] of this._cached_textures) this.deleteTexture(s, a);
 }
 incrementTime() {
  for (var [ t, e ] of this._cached_textures) t.idleTime = t.idleTime + 1;
 }
 _formatToGL(t) {
  switch (t) {
  case Texture.FORMAT.R8:
   return this._gl.R8;

  case Texture.FORMAT.RED:
   return this._gl.RED;

  case Texture.FORMAT.RED_INTEGER:
   return this._gl.RED_INTEGER;

  case Texture.FORMAT.RGBA:
   return this._gl.RGBA;

  case Texture.FORMAT.RGB:
   return this._gl.RGB;

  case Texture.FORMAT.ALPHA:
   return this._gl.ALPHA;

  case Texture.FORMAT.LUMINANCE:
   return this._gl.LUMINANCE;

  case Texture.FORMAT.LUMINANCE_ALPHA:
   return this._gl.LUMINANCE_ALPHA;

  case Texture.FORMAT.DEPTH_COMPONENT:
   return this._gl.DEPTH_COMPONENT;

  case Texture.FORMAT.DEPTH_COMPONENT24:
   return this._gl.DEPTH_COMPONENT24;

  case Texture.FORMAT.DEPTH_COMPONENT32F:
   return this._gl.DEPTH_COMPONENT32F;

  case Texture.FORMAT.RGB16F:
   return this._gl.RGB16F;

  case Texture.FORMAT.RGB32F:
   return this._gl.RGB32F;

  case Texture.FORMAT.RGBA16F:
   return this._gl.RGBA16F;

  case Texture.FORMAT.RGBA32F:
   return this._gl.RGBA32F;

  case Texture.FORMAT.R16F:
   return this._gl.R16F;

  case Texture.FORMAT.R32F:
   return this._gl.R32F;

  case Texture.FORMAT.R32I:
   return this._gl.R32I;

  case Texture.FORMAT.R32UI:
   return this._gl.R32UI;

  default:
   return console.warn("Warning: Received unsupported texture format: [" + t + "]!"), 
   this._gl.RGBA;
  }
 }
 _magFilterToGL(t) {
  switch (t) {
  case Texture.FILTER.NearestFilter:
   return this._gl.NEAREST;

  case Texture.FILTER.LinearFilter:
   return this._gl.LINEAR;

  default:
   return console.warn("Warning: Received unsupported texture filter: [" + t + "]!"), 
   this._gl.LINEAR;
  }
 }
 _minFilterToGL(t) {
  switch (t) {
  case Texture.FILTER.NearestFilter:
   return this._gl.NEAREST;

  case Texture.FILTER.LinearFilter:
   return this._gl.LINEAR;

  case Texture.FILTER.NearestMipMapNearestFilter:
   return this._gl.NEAREST_MIPMAP_NEAREST;

  case Texture.FILTER.NearestMipMapLinearFilter:
   return this._gl.NEAREST_MIPMAP_LINEAR;

  case Texture.FILTER.LinearMipMapNearestFilter:
   return this._gl.LINEAR_MIPMAP_NEAREST;

  case Texture.FILTER.LinearMipMapLinearFilter:
   return this._gl.LINEAR_MIPMAP_LINEAR;

  default:
   return console.warn("Warning: Received unsupported texture filter: [" + t + "]!"), 
   this._gl.LINEAR;
  }
 }
 _wrapToGL(t) {
  switch (t) {
  case Texture.WRAPPING.RepeatWrapping:
   return this._gl.REPEAT;

  case Texture.WRAPPING.ClampToEdgeWrapping:
   return this._gl.CLAMP_TO_EDGE;

  case Texture.WRAPPING.MirroredRepeatWrapping:
   return this._gl.MIRRORED_REPEAT;

  default:
   return console.warn("Warning: Received unsupported texture wrap: [" + t + "]!"), 
   this._gl.CLAMP_TO_EDGE;
  }
 }
 _typeToGL(t) {
  switch (t) {
  case Texture.TYPE.UNSIGNED_BYTE:
   return this._gl.UNSIGNED_BYTE;

  case Texture.TYPE.UNSIGNED_INT_24_8:
   return this._gl.UNSIGNED_INT_24_8;

  case Texture.TYPE.UNSIGNED_SHORT:
   return this._gl.UNSIGNED_SHORT;

  case Texture.TYPE.UNSIGNED_INT:
   return this._gl.UNSIGNED_INT;

  case Texture.TYPE.INT:
   return this._gl.INT;

  case Texture.TYPE.FLOAT:
   return this._gl.FLOAT;

  case Texture.TYPE.HALF_FLOAT:
   return this._gl.HALF_FLOAT;

  default:
   return console.warn("Warning: Received unsupported texture type: [" + t + "] (using default)!"), 
   this._gl.UNSIGNED_BYTE;
  }
 }
}

class Geometry {
 constructor(t = {}) {
  this._uuid = _Math.generateUUID(), this.type = "Geometry", this._indices = void 0 !== t.indices ? t.indices : null, 
  this._vertices = void 0 !== t.vertices ? t.vertices : null, this._normals = void 0 !== t.normals ? t.normals : null, 
  this._tangents = void 0 !== t.tangents ? t.tangents : null, this._bitangents = void 0 !== t.bitangents ? t.bitangents : null, 
  this._vertColor = void 0 !== t.vertColor ? t.vertColor : null, this._uv = void 0 !== t.uv ? t.uv : null, 
  this._wireframeIndices = void 0 !== t.wireframeIndices ? t.wireframeIndices : null, 
  this._MMat = void 0 !== t.MMat ? t.MMat : null, this._translation = void 0 !== t.translation ? t.translation : null, 
  this._boundingBox = null, this._boundingSphere = null, this._onChangeListener = null, 
  this._drawWireframe = !1;
 }
 buildWireframeBuffer() {
  var i, r, s, a = new Map(), n = [];
  if (null !== this._indices && 0 < this._indices.count()) {
   var o, h, u, l = this._indices.array;
   for (let t = 0, e = l.length; t < e; t += 3) o = l[t], h = l[t + 1], u = l[t + 2], 
   this.sanitize(a, o, h, n), this.sanitize(a, h, u, n), this.sanitize(a, u, o, n);
  } else {
   if (!(null !== this._vertices && 0 < this._vertices.count())) return;
   for (let t = 0, e = this._vertices.array.length / 3 - 1; t < e; t += 3) r = (i = t) + 1, 
   s = t + 2, n.push(i, r, r, s, s, i);
  }
  this.wireframeIndices = new BufferAttribute(new Uint32Array(n), 1);
 }
 checkContamination(e, i, r, s) {
  for (let t = s = (s = 6 * s - 18) < 0 ? 0 : s; t < e.length; t += 2) if (e[t] === i && e[t + 1] === r || e[t] === r && e[t + 1] === i) return !0;
  return !1;
 }
 sanitize(t, e, i, r) {
  let s = !1, a = !1, n = !1, o = !1, h, u;
  if (t.has(e)) {
   s = !0, h = t.get(e);
   for (let t = 0; t < h.length; t++) if (h[t] === i) {
    n = !0;
    break;
   }
  }
  if (t.has(i)) {
   a = !0, u = t.get(i);
   for (let t = 0; t < u.length; t++) if (u[t] === e) {
    o = !0;
    break;
   }
  }
  s || t.set(e, [ i ]), a || t.set(i, [ e ]), s && !n && h.push(i), a && !o && u.push(e), 
  s && a && n && o || r.push(e, i);
 }
 _normalizeNormals() {
  for (var t, e, i, r = this._normals.array, s = 0; s < r.length; s += 3) i = r[s], 
  t = r[s + 1], e = r[s + 2], i = 1 / Math.sqrt(i * i + t * t + e * e), r[s] *= i, 
  r[s + 1] *= i, r[s + 2] *= i;
 }
 computeVertexNormals() {
  if (this.vertices) {
   var t = this.vertices.array;
   if (this._normals) for (var e = this._normals.array, i = 0; i < e.length; i++) e[i] = 0; else this.normals = new BufferAttribute(new Float32Array(t.length), 3);
   var r, s, a, n = this._normals.array, o = new Vector3(), h = new Vector3(), u = new Vector3(), l = new Vector3(), _ = new Vector3();
   if (this.indices) for (var c = this.indices.array, i = 0; i < c.length; i += 3) r = 3 * c[i], 
   s = 3 * c[i + 1], a = 3 * c[i + 2], o.fromArray(t, r), h.fromArray(t, s), u.fromArray(t, a), 
   l.subVectors(u, h), _.subVectors(o, h), l.cross(_), n[r] += l.x, n[1 + r] += l.y, 
   n[2 + r] += l.z, n[s] += l.x, n[1 + s] += l.y, n[2 + s] += l.z, n[a] += l.x, 
   n[1 + a] += l.y, n[2 + a] += l.z; else for (i = 0; i < t.length; i += 9) o.fromArray(t, i), 
   h.fromArray(t, i + 3), u.fromArray(t, i + 6), l.subVectors(u, h), _.subVectors(o, h), 
   l.cross(_), n[i] = l.x, n[i + 1] = l.y, n[i + 2] = l.z, n[i + 3] = l.x, n[i + 4] = l.y, 
   n[i + 5] = l.z, n[i + 6] = l.x, n[i + 7] = l.y, n[i + 8] = l.z;
   this._normalizeNormals(), this._normals.needsUpdate = !0;
  }
 }
 computeVertexTangents() {
  if (this.indices) {
   var e = this.indices, i = this.vertices, r = this.uv, s = new Vector3(), a = new Vector3(), n = new Vector3(), o = new Vector2(), h = new Vector2(), u = new Vector2(), l = new Vector3(), _ = new Vector3(), c = new Vector2(), d = new Vector2(), m = new Vector3(), g = new Array(i.count() * i.itemSize);
   for (let t = 0; t < e.count(); t += 3) {
    s.x = i.array[e.array[t + 0] * i.itemSize + 0], s.y = i.array[e.array[t + 0] * i.itemSize + 1], 
    s.z = i.array[e.array[t + 0] * i.itemSize + 2], a.x = i.array[e.array[t + 1] * i.itemSize + 0], 
    a.y = i.array[e.array[t + 1] * i.itemSize + 1], a.z = i.array[e.array[t + 1] * i.itemSize + 2], 
    n.x = i.array[e.array[t + 2] * i.itemSize + 0], n.y = i.array[e.array[t + 2] * i.itemSize + 1], 
    n.z = i.array[e.array[t + 2] * i.itemSize + 2], o.x = r.array[e.array[t + 0] * r.itemSize + 0], 
    o.y = r.array[e.array[t + 0] * r.itemSize + 1], h.x = r.array[e.array[t + 1] * r.itemSize + 0], 
    h.y = r.array[e.array[t + 1] * r.itemSize + 1], u.x = r.array[e.array[t + 2] * r.itemSize + 0], 
    u.y = r.array[e.array[t + 2] * r.itemSize + 1], l.subVectors(a, s), _.subVectors(n, s), 
    c.subVectors(h, o), d.subVectors(u, o);
    var p = 1 / (c.x * d.y - c.y * d.x);
    m.subVectors(l.multiplyScalar(d.y), _.multiplyScalar(c.y)).multiplyScalar(p), 
    m.normalize(), g[e.array[t + 0] * i.itemSize + 0] = m.x, g[e.array[t + 0] * i.itemSize + 1] = m.y, 
    g[e.array[t + 0] * i.itemSize + 2] = m.z, g[e.array[t + 1] * i.itemSize + 0] = m.x, 
    g[e.array[t + 1] * i.itemSize + 1] = m.y, g[e.array[t + 1] * i.itemSize + 2] = m.z, 
    g[e.array[t + 2] * i.itemSize + 0] = m.x, g[e.array[t + 2] * i.itemSize + 1] = m.y, 
    g[e.array[t + 2] * i.itemSize + 2] = m.z;
   }
   this.tangents = new Float32Attribute(g, i.itemSize);
  } else {
   var f = this.vertices, y = this.uv, T = new Vector3(), x = new Vector3(), S = new Vector3(), E = new Vector2(), A = new Vector2(), R = new Vector2(), v = new Vector3(), P = new Vector3(), w = new Vector2(), M = new Vector2(), b = new Vector3(), L = new Array(f.count() * f.itemSize);
   for (let t = 0; t < f.count(); t += 3) {
    T.x = f.array[t * f.itemSize + 0], T.y = f.array[t * f.itemSize + 1], T.z = f.array[t * f.itemSize + 2], 
    x.x = f.array[t * f.itemSize + 3], x.y = f.array[t * f.itemSize + 4], x.z = f.array[t * f.itemSize + 5], 
    S.x = f.array[t * f.itemSize + 6], S.y = f.array[t * f.itemSize + 7], S.z = f.array[t * f.itemSize + 8], 
    E.x = y.array[t * y.itemSize + 0], E.y = y.array[t * y.itemSize + 1], A.x = y.array[t * y.itemSize + 2], 
    A.y = y.array[t * y.itemSize + 3], R.x = y.array[t * y.itemSize + 4], R.y = y.array[t * y.itemSize + 5], 
    v.subVectors(x, T), P.subVectors(S, T), w.subVectors(A, E), M.subVectors(R, E);
    var C = 1 / (w.x * M.y - w.y * M.x);
    b.subVectors(v.multiplyScalar(M.y), P.multiplyScalar(w.y)).multiplyScalar(C), 
    b.normalize(), L[t * f.itemSize + 0] = b.x, L[t * f.itemSize + 1] = b.y, L[t * f.itemSize + 2] = b.z, 
    L[t * f.itemSize + 3] = b.x, L[t * f.itemSize + 4] = b.y, L[t * f.itemSize + 5] = b.z, 
    L[t * f.itemSize + 6] = b.x, L[t * f.itemSize + 7] = b.y, L[t * f.itemSize + 8] = b.z;
   }
   this.tangents = new Float32Attribute(L, f.itemSize);
  }
 }
 computeVertexBitangents() {
  if (this.indices) {
   var e = this.indices, i = this.vertices, r = this.uv, s = new Vector3(), a = new Vector3(), n = new Vector3(), o = new Vector2(), h = new Vector2(), u = new Vector2(), l = new Vector3(), _ = new Vector3(), c = new Vector2(), d = new Vector2(), m = new Vector3(), g = new Array(i.count() * i.itemSize);
   for (let t = 0; t < e.count(); t += 3) {
    s.x = i.array[e.array[t + 0] * i.itemSize + 0], s.y = i.array[e.array[t + 0] * i.itemSize + 1], 
    s.z = i.array[e.array[t + 0] * i.itemSize + 2], a.x = i.array[e.array[t + 1] * i.itemSize + 0], 
    a.y = i.array[e.array[t + 1] * i.itemSize + 1], a.z = i.array[e.array[t + 1] * i.itemSize + 2], 
    n.x = i.array[e.array[t + 2] * i.itemSize + 0], n.y = i.array[e.array[t + 2] * i.itemSize + 1], 
    n.z = i.array[e.array[t + 2] * i.itemSize + 2], o.x = r.array[e.array[t + 0] * r.itemSize + 0], 
    o.y = r.array[e.array[t + 0] * r.itemSize + 1], h.x = r.array[e.array[t + 1] * r.itemSize + 0], 
    h.y = r.array[e.array[t + 1] * r.itemSize + 1], u.x = r.array[e.array[t + 2] * r.itemSize + 0], 
    u.y = r.array[e.array[t + 2] * r.itemSize + 1], l.subVectors(a, s), _.subVectors(n, s), 
    c.subVectors(h, o), d.subVectors(u, o);
    var p = 1 / (c.x * d.y - c.y * d.x);
    m.subVectors(_.multiplyScalar(c.x), l.multiplyScalar(d.x)).multiplyScalar(p), 
    m.normalize(), g[e.array[t + 0] * i.itemSize + 0] = m.x, g[e.array[t + 0] * i.itemSize + 1] = m.y, 
    g[e.array[t + 0] * i.itemSize + 2] = m.z, g[e.array[t + 1] * i.itemSize + 0] = m.x, 
    g[e.array[t + 1] * i.itemSize + 1] = m.y, g[e.array[t + 1] * i.itemSize + 2] = m.z, 
    g[e.array[t + 2] * i.itemSize + 0] = m.x, g[e.array[t + 2] * i.itemSize + 1] = m.y, 
    g[e.array[t + 2] * i.itemSize + 2] = m.z;
   }
   this.bitangents = new Float32Attribute(g, i.itemSize);
  } else {
   var f = this.vertices, y = this.uv, T = new Vector3(), x = new Vector3(), S = new Vector3(), E = new Vector2(), A = new Vector2(), R = new Vector2(), v = new Vector3(), P = new Vector3(), w = new Vector2(), M = new Vector2(), b = new Vector3(), L = new Array(f.count() * f.itemSize);
   for (let t = 0; t < f.count(); t += 3) {
    T.x = f.array[t * f.itemSize + 0], T.y = f.array[t * f.itemSize + 1], T.z = f.array[t * f.itemSize + 2], 
    x.x = f.array[t * f.itemSize + 3], x.y = f.array[t * f.itemSize + 4], x.z = f.array[t * f.itemSize + 5], 
    S.x = f.array[t * f.itemSize + 6], S.y = f.array[t * f.itemSize + 7], S.z = f.array[t * f.itemSize + 8], 
    E.x = y.array[t * y.itemSize + 0], E.y = y.array[t * y.itemSize + 1], A.x = y.array[t * y.itemSize + 2], 
    A.y = y.array[t * y.itemSize + 3], R.x = y.array[t * y.itemSize + 4], R.y = y.array[t * y.itemSize + 5], 
    v.subVectors(x, T), P.subVectors(S, T), w.subVectors(A, E), M.subVectors(R, E);
    var C = 1 / (w.x * M.y - w.y * M.x);
    b.subVectors(P.multiplyScalar(w.x), v.multiplyScalar(M.x)).multiplyScalar(C), 
    b.normalize(), L[t * f.itemSize + 0] = b.x, L[t * f.itemSize + 1] = b.y, L[t * f.itemSize + 2] = b.z, 
    L[t * f.itemSize + 3] = b.x, L[t * f.itemSize + 4] = b.y, L[t * f.itemSize + 5] = b.z, 
    L[t * f.itemSize + 6] = b.x, L[t * f.itemSize + 7] = b.y, L[t * f.itemSize + 8] = b.z;
   }
   this.bitangents = new Float32Attribute(L, f.itemSize);
  }
 }
 computeVertexNormalsIdxRange(t, e) {
  if (this.vertices && this.indices) {
   var i = this.vertices.array;
   if (this._normals) for (var r = this._normals.array, s = 0; s < r.length; s++) r[s] = 0; else this.normals = new BufferAttribute(new Float32Array(i.length), 3);
   for (var a, n, o, h = this._normals.array, u = new Vector3(), l = new Vector3(), _ = new Vector3(), c = new Vector3(), d = new Vector3(), m = this.indices.array, s = t, g = t + e; s < g; s += 3) a = 3 * m[s], 
   n = 3 * m[s + 1], o = 3 * m[s + 2], u.fromArray(i, a), l.fromArray(i, n), _.fromArray(i, o), 
   c.subVectors(_, l), d.subVectors(u, l), c.cross(d), h[a] += c.x, h[1 + a] += c.y, 
   h[2 + a] += c.z, h[n] += c.x, h[1 + n] += c.y, h[2 + n] += c.z, h[o] += c.x, 
   h[1 + o] += c.y, h[2 + o] += c.z;
   this._normalizeNormals(), this._normals.needsUpdate = !0;
  }
 }
 computeBoundingBox() {
  null === this._boundingBox && (this._boundingBox = new Box3()), this._vertices ? this._boundingBox.setFromArray(this._vertices.array) : this._boundingBox.makeEmpty(), 
  (isNaN(this._boundingBox.min.x) || isNaN(this._boundingBox.min.y) || isNaN(this._boundingBox.min.z)) && console.error("Geometry error: One or more of bounding box axis min is NaN.");
 }
 computeBoundingSphere() {
  var t = new Box3(), i = new Vector3();
  if (null === this._boundingSphere && (this._boundingSphere = new Sphere()), this._vertices) {
   var r = this._vertices.array, s = this._boundingSphere.center;
   t.setFromArray(r), t.center(s);
   let e = 0;
   for (let t = 0; t < r.length; t += 3) i.fromArray(r, t), e = Math.max(e, s.distanceToSquared(i));
   this._boundingSphere.radius = Math.sqrt(e), isNaN(this._boundingSphere.radius) && console.error("Geometry error: Bounding sphere radius is NaN.");
  }
 }
 setDrawRange(t, e) {
  this._indices ? (this._indexStart = t, this._indexCount = e, this._drawRangeSet = !0) : console.error("Geometry error: setDrawRange called before indices were set.");
 }
 get indexStart() {
  return this._drawRangeSet ? this._indexStart : 0;
 }
 get indexCount() {
  return this._drawRangeSet ? this._indexCount : this.indices.count();
 }
 get indices() {
  return this._indices;
 }
 get vertices() {
  return this._vertices;
 }
 get normals() {
  return null === this._normals && this.computeVertexNormals(), this._normals;
 }
 get tangents() {
  return this._tangents;
 }
 get bitangents() {
  return this._bitangents;
 }
 get vertColor() {
  return this._vertColor;
 }
 get uv() {
  return this._uv;
 }
 get wireframeIndices() {
  return null === this._wireframeIndices && this.buildWireframeBuffer(), this._wireframeIndices;
 }
 get MMat() {
  return this._MMat;
 }
 get translation() {
  return this._translation;
 }
 get drawWireframe() {
  return this._drawWireframe;
 }
 get boundingBox() {
  return this._boundingBox;
 }
 get boundingSphere() {
  return null === this._boundingSphere && this.computeBoundingSphere(), this._boundingSphere;
 }
 set indices(t) {
  this._indices = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    array: this._indices.array.buffer.slice(0),
    itemSize: this._indices.itemSize
   }
  }, this._onChangeListener.geometryUpdate(t)), this._indices.target = BufferAttribute.TARGET.ELEMENT_ARRAY_BUFFER;
 }
 set vertices(t) {
  this._vertices = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    array: this._vertices.array.buffer.slice(0),
    itemSize: this._vertices.itemSize
   }
  }, this._onChangeListener.geometryUpdate(t)), this._vertices.target = BufferAttribute.TARGET.ARRAY_BUFFER;
 }
 set normals(t) {
  this._normals = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    array: this._normals.array.buffer.slice(0),
    itemSize: this._normals.itemSize
   }
  }, this._onChangeListener.geometryUpdate(t)), this._normals.target = BufferAttribute.TARGET.ARRAY_BUFFER;
 }
 set tangents(t) {
  this._tangents = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    array: this._tangents.array.buffer.slice(0),
    itemSize: this._tangents.itemSize
   }
  }, this._onChangeListener.geometryUpdate(t)), this._tangents.target = BufferAttribute.TARGET.ARRAY_BUFFER;
 }
 set bitangents(t) {
  this._bitangents = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    array: this._bitangents.array.buffer.slice(0),
    itemSize: this._bitangents.itemSize
   }
  }, this._onChangeListener.geometryUpdate(t)), this._bitangents.target = BufferAttribute.TARGET.ARRAY_BUFFER;
 }
 set vertColor(t) {
  this._vertColor = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    array: this._vertColor.array.buffer.slice(0),
    itemSize: this._vertColor.itemSize
   }
  }, this._onChangeListener.geometryUpdate(t)), this._vertColor.target = BufferAttribute.TARGET.ARRAY_BUFFER;
 }
 set uv(t) {
  this._uv = t, this._uv.target = BufferAttribute.TARGET.ARRAY_BUFFER;
 }
 set wireframeIndices(t) {
  this._wireframeIndices = t, this._wireframeIndices.target = BufferAttribute.TARGET.ELEMENT_ARRAY_BUFFER;
 }
 set MMat(t) {
  this._MMat = t, this._MMat.target = BufferAttribute.TARGET.ARRAY_BUFFER;
 }
 set translation(t) {
  this._translation = t, this._translation.target = BufferAttribute.TARGET.ARRAY_BUFFER;
 }
 set drawWireframe(t) {
  this._drawWireframe = t;
 }
 set onChangeListener(t) {
  this._onChangeListener = t;
 }
 toJson() {
  var t = {};
  return t._uuid = this._uuid, t.type = this.type, this._indices && (t.indices = {
   array: this._indices.array.buffer.slice(0),
   itemSize: this._indices.itemSize
  }), this._vertices && (t.vertices = {
   array: this._vertices.array.buffer.slice(0),
   itemSize: this._vertices.itemSize
  }), this._normals && (t.normals = {
   array: this._normals.array.buffer.slice(0),
   itemSize: this._normals.itemSize
  }), this._vertColor && (t.vertColor = {
   array: this._vertColor.array.buffer.slice(0),
   itemSize: this._vertColor.itemSize
  }), t;
 }
 static fromJson(t) {
  var e = new Geometry();
  return e._uuid = t._uuid, t.indices && (e._indices = Uint32Attribute(t.indices.array, t.indices.itemSize)), 
  t.vertices && (e._vertices = Float32Attribute(t.vertices.array, t.vertices.itemSize)), 
  t.normals && (e._normals = Float32Attribute(t.normals.array, t.normals.itemSize)), 
  t.vertColor && (e._vertColor = Float32Attribute(t.vertColor.array, t.vertColor.itemSize)), 
  e;
 }
 update(t) {
  for (var e in t) switch (e) {
  case "indices":
   this.indices = Uint32Attribute(t.indices.array, t.indices.itemSize), delete t.indices;
   break;

  case "vertices":
   this.vertices = Float32Attribute(t.vertices.array, t.vertices.itemSize), delete t.vertices;
   break;

  case "normals":
   this.normals = Float32Attribute(t.normals.array, t.normals.itemSize), delete t.normals;
   break;

  case "tangents":
   this.tangents = Float32Attribute(t.tangents.array, t.tangents.itemSize), delete t.tangents;
   break;

  case "bitangents":
   this.bitangents = Float32Attribute(t.bitangents.array, t.bitangents.itemSize), 
   delete t.bitangents;
   break;

  case "vertColor":
   this.vertColor = Float32Attribute(t.vertColor.array, t.vertColor.itemSize), delete t.vertColor;
   break;

  default:
   console.warn("Uknown property!");
  }
 }
}

class Material {
 constructor() {
  if (new.target === Material) throw new TypeError("Cannot construct abstract Material class.");
  this._uuid = _Math.generateUUID(), this.type = "Material", this._onChangeListener = null, 
  this._name = "", this._side = FRONT_SIDE, this._depthFunc = FUNC_LEQUAL, this._depthTest = !0, 
  this._depthWrite = !0, this._transparent = !1, this._opacity = 1, this._useVertexColors = !1, 
  this.requiredProgramTemplate = null, this._usePoints = !1, this._pointSize = 1, 
  this._pointsScale = !0, this._drawCircles = !1, this._useClippingPlanes = !1, 
  this._clippingPlanes = null, this._programName = "base", this._shadingType = SmoothShading, 
  this._lights = !0, this._maps = [], this._cubemaps = [], this._diffuseMap = null, 
  this._specularMap = null, this._normalMap = null, this._heightMap = null, this._instanceData = [], 
  this._normalFlat = !1, this._heightScale = .125, this._blinn = !0, this._flags = [], 
  this._values = {}, this._instanced = !1, this._instancedTranslation = !1, this._receiveShadows = !0;
 }
 get requiredProgramTemplate() {
  return this._requiredProgramTemplate;
 }
 set requiredProgramTemplate(t) {
  this._requiredProgramTemplate = t;
 }
 set onChangeListener(t) {
  this._onChangeListener = t;
 }
 set name(t) {
  t !== this._name && (this._name = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    name: this._name
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set side(t) {
  t !== this._side && (this._side = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    side: this._side
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set depthFunc(t) {
  t !== this._depthFunc && (this._depthFunc = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    depthFunc: this._depthFunc
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set depthTest(t) {
  t !== this._depthTest && (this._depthTest = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    depthTest: this._depthTest
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set depthWrite(t) {
  t !== this._depthWrite && (this._depthWrite = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    depthWrite: this._depthWrite
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set transparent(t) {
  t !== this._transparent && (this._transparent = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    transparent: this._transparent
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set opacity(t) {
  t !== this._opacity && (this._opacity = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    opacity: this._opacity
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set useVertexColors(t) {
  t !== this._useVertexColors && (this.requiredProgramTemplate = null, this._useVertexColors = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    useVertexColors: this._useVertexColors
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set usePoints(t) {
  t !== this._usePoints && (this.requiredProgramTemplate = null, this._usePoints = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    usePoints: this._usePoints
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set pointSize(t) {
  t !== this._pointSize && (this.requiredProgramTemplate = null, this._pointSize = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    pointSize: this._pointSize
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set pointsScale(t) {
  t !== this._pointsScale && (this.requiredProgramTemplate = null, this._pointsScale = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    pointsScale: this._pointsScale
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set drawCircles(t) {
  t !== this._drawCircles && (this.requiredProgramTemplate = null, this._drawCircles = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    drawCircles: this._drawCircles
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set useClippingPlanes(t) {
  t !== this._useClippingPlanes && (this.requiredProgramTemplate = null, this._useClippingPlanes = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    useClippingPlanes: this._useClippingPlanes
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set clippingPlanes(t) {
  t !== this._clippingPlanes && (this.requiredProgramTemplate = null, this._clippingPlanes = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    clippingPlanes: this._clippingPlanes
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set shadingType(t) {
  t !== this._shadingType && (this.requiredProgramTemplate = null, this._shadingType = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    shadingType: this._shadingType
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set instanced(t) {
  t !== this._instanced && (this.requiredProgramTemplate = null, this._instanced = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    instanced: this._instanced
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set instancedTranslation(t) {
  t !== this._instancedTranslation && (this.requiredProgramTemplate = null, this._instancedTranslation = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    instancedTranslation: this._instancedTranslation
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set heightScale(t) {
  t !== this._heightScale && (this.requiredProgramTemplate = null, this._heightScale = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    heightScale: this._heightScale
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set blinn(t) {
  t !== this._blinn && (this.requiredProgramTemplate = null, this._blinn = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    blinn: this._blinn
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set receiveShadows(t) {
  t !== this._receiveShadows && (this.requiredProgramTemplate = null, this._receiveShadows = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    receiveShadows: this._receiveShadows
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set lights(t) {
  this._lights !== t && (this.requiredProgramTemplate = null, this._lights = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    lights: this._lights
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set programName(t) {
  this._programName = t;
 }
 get name() {
  return this._name;
 }
 get side() {
  return this._side;
 }
 get depthFunc() {
  return this._depthFunc;
 }
 get depthTest() {
  return this._depthTest;
 }
 get depthWrite() {
  return this._depthWrite;
 }
 get transparent() {
  return this._transparent;
 }
 get opacity() {
  return this._opacity;
 }
 get useVertexColors() {
  return this._useVertexColors;
 }
 get usePoints() {
  return this._usePoints;
 }
 get pointSize() {
  return this._pointSize;
 }
 get pointsScale() {
  return this._pointsScale;
 }
 get drawCircles() {
  return this._drawCircles;
 }
 get useClippingPlanes() {
  return this._useClippingPlanes;
 }
 get clippingPlanes() {
  return this._clippingPlanes;
 }
 get shadingType() {
  return this._shadingType;
 }
 get instanced() {
  return this._instanced;
 }
 get instancedTranslation() {
  return this._instancedTranslation;
 }
 get heightScale() {
  return this._heightScale;
 }
 get blinn() {
  return this._blinn;
 }
 get receiveShadows() {
  return this._receiveShadows;
 }
 get lights() {
  return this._lights;
 }
 get maps() {
  return this._maps;
 }
 get cubemaps() {
  return this._cubemaps;
 }
 get diffuseMap() {
  return this._diffuseMap;
 }
 get specularMap() {
  return this._specularMap;
 }
 get normalMap() {
  return this._normalMap;
 }
 get heightMap() {
  return this._heightMap;
 }
 get instanceData() {
  return this._instanceData;
 }
 get normalFlat() {
  return this._normalFlat;
 }
 set normalFlat(t) {
  this.requiredProgramTemplate = null, this._normalFlat = t;
 }
 get programName() {
  return this._programName;
 }
 get programName2() {
  switch (this.shadingType) {
  case FlatShading:
   return this.programName + "-FLAT";

  case GouraudShading:
   return this.programName + "-GOURAUD";

  case PhongShading:
   return this.programName + "-PHONG";

  default:
   SmoothShading;
   return this.programName;
  }
 }
 get values() {
  return this._values;
 }
 set values(t) {
  this._values = t;
 }
 get flags() {
  return this._flags;
 }
 set flags(t) {
  this._flags = t;
 }
 addMap(t) {
  this.requiredProgramTemplate = null, this._maps.push(t);
 }
 addCubemap(t) {
  this.requiredProgramTemplate = null, this._cubemaps.push(t);
 }
 set diffuseMap(t) {
  this.requiredProgramTemplate = null, this._diffuseMap = t;
 }
 set specularMap(t) {
  this.requiredProgramTemplate = null, this._specularMap = t;
 }
 set normalMap(t) {
  this.requiredProgramTemplate = null, this._normalMap = t;
 }
 set heightMap(t) {
  this.requiredProgramTemplate = null, this._heightMap = t;
 }
 addInstanceData(t) {
  this.requiredProgramTemplate = null, this._instanceData.push(t);
 }
 removeMap(t) {
  t = this._maps.indexOf(t);
  -1 < t && (this.requiredProgramTemplate = null, this._maps.splice(t, 1));
 }
 removeCubemap(t) {
  t = this._cubemaps.indexOf(t);
  -1 < t && (this.requiredProgramTemplate = null, this._cubemaps.splice(t, 1));
 }
 clearMaps() {
  this.requiredProgramTemplate = null, this._maps = [];
 }
 clearCubemaps() {
  this.requiredProgramTemplate = null, this._cubemaps = [];
 }
 resetProgramFlagsAndValues() {
  this._flags = [], this._values = {}, this._lights && this._flags.push("LIGHTS"), 
  this._useVertexColors && this._flags.push("COLORS"), 0 < this._maps.length && (this._flags.push("TEXTURE"), 
  this._values.NUM_TEX = this._maps.length), 0 < this._cubemaps.length && (this._flags.push("CUBETEXTURES"), 
  this._values.NUM_CUBETEXTURES = this._cubemaps.length), this._side === FRONT_SIDE ? this._flags.push("FRONT_SIDE") : this._side === BACK_SIDE ? this._flags.push("BACK_SIDE") : this._side === FRONT_AND_BACK_SIDE && this._flags.push("FRONT_AND_BACK_SIDE"), 
  this._usePoints && this._flags.push("POINTS"), this._pointsScale && this._flags.push("POINTS_SCALE"), 
  this._drawCircles && this.flags.push("CIRCLES"), this._useClippingPlanes && (this._flags.push("CLIPPING_PLANES"), 
  this._values.NUM_CLIPPING_PLANES = this._clippingPlanes.length), this._shadingType === SmoothShading ? this._flags.push("SMOOTH_SHADING") : this._flags.push("FLAT_SHADING"), 
  !0 === this._transparent && this._flags.push("TRANSPARENT"), !0 === this._instanced && this._flags.push("INSTANCED"), 
  !0 === this._instancedTranslation && this._flags.push("INSTANCED_TRANSLATION"), 
  this._diffuseMap && this._flags.push("DIFFUSE_MAP"), this._specularMap && this._flags.push("SPECULAR_MAP"), 
  this._normalMap && this._flags.push("NORMAL_MAP"), this._heightMap && this._flags.push("HEIGHT_MAP"), 
  this._normalFlat && this._flags.push("NORMAL_FLAT");
 }
 toJson() {
  var t = {};
  return t._uuid = this._uuid, t.type = this.type, t.name = this._name, t.side = this._side, 
  t.depthFunc = this._depthFunc, t.depthTest = this._depthTest, t.depthWrite = this._depthWrite, 
  t.transparent = this._transparent, t.opacity = this._opacity, t.useVertexColors = this._useVertexColors, 
  t.lights = this._lights, t;
 }
 static fromJson(t, e) {
  return (e = e || new Material())._uuid = t._uuid, e._name = t.name, e._side = t.side, 
  e._depthFunc = t.depthFunc, e._depthTest = t.depthTest, e._depthWrite = t.depthWrite, 
  e._transparent = t.transparent, e._opacity = t.opacity, e._useVertexColors = t.useVertexColors, 
  e._lights = t.lights, e;
 }
 update(t) {
  for (var e in t) switch (e) {
  case "opacity":
   this._opacity = t.opacity, delete t.opacity;
   break;

  case "transparent":
   this._transparent = t.transparent, delete t.transparent;
   break;

  case "side":
   this._side = t.side, delete t.side;
   break;

  case "depthFunc":
   this._depthFunc = t.depthFunc, delete t.depthFunc;
   break;

  case "depthTest":
   this._depthTest = t.depthTest, delete t.depthTest;
   break;

  case "depthWrite":
   this._depthWrite = t.depthWrite, delete t.depthWrite;
   break;

  case "useVertexColors":
   this._useVertexColors = t.useVertexColors, delete t.useVertexColors;
   break;

  case "name":
   this._name = t.name, delete t.name;
   break;

  case "usePoints":
   this._usePoints = t.usePoints, delete t.usePoints;
   break;

  case "pointSize":
   this._pointSize = t.pointSize, delete t.pointSize;
   break;

  case "pointsScale":
   this._pointsScale = t.pointsScale, delete t.pointsScale;
   break;

  case "drawCircles":
   this._drawCircles = t.drawCircles, delete t.drawCircles;
   break;

  case "useClippingPlanes":
   this._useClippingPlanes = t.useClippingPlanes, delete t.useClippingPlanes;
   break;

  case "clippingPlanes":
   this._clippingPlanes = t.clippingPlanes, delete t.clippingPlanes;
   break;

  case "shadingType":
   this._shadingType = t.shadingType, delete t.shadingType;
   break;

  case "instanced":
   this._instanced = t.instanced, delete t.instanced;
   break;

  case "instancedTranslation":
   this._instancedTranslation = t.instancedTranslation, delete t.instancedTranslation;
   break;

  case "lights":
   this._lights = t.lights, delete t.lights;
  }
 }
}

class MaterialProgramTemplate {
 constructor(t, e, i, r = void 0) {
  this.name = t, this.flags = e, this.values = i, this.programID = this._generateProgramID(r);
 }
 _generateProgramID(t = void 0) {
  for (var e = this.flags.sort(), i = Object.keys(this.values).sort(), r = this.name, s = 0; s < e.length; s++) r += "|" + e[s];
  for (s = 0; s < i.length; s++) r += i[s] + this.values[i[s]];
  return void 0 !== t ? t.generateMaterialID(r) : r;
 }
 compare(t) {
  return this.programID === t.programID;
 }
}

class MeshBasicMaterial extends Material {
 constructor() {
  super(Material), this.type = "MeshBasicMaterial", this._emissive = new Color(0 * Math.random()), 
  this._color = new Color(16777215 * Math.random()), this.programName = "basic";
 }
 set emissive(t) {
  t.equals(this._emissive) || (this._emissive = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    emissive: this._emissive.getHex()
   }
  }, this._onChangeListener.materialUpdate(t)));
 }
 set color(t) {
  t.equals(this._color) || (this._color = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    color: this._color.getHex()
   }
  }, this._onChangeListener.materialUpdate(t)));
 }
 get emissive() {
  return this._emissive;
 }
 get color() {
  return this._color;
 }
 resetProgramFlagsAndValues() {
  super.resetProgramFlagsAndValues();
 }
 requiredProgram(t = void 0) {
  return null === this.requiredProgramTemplate && (this.resetProgramFlagsAndValues(), 
  this.requiredProgramTemplate = new MaterialProgramTemplate(this.programName2, this.flags, this.values, t)), 
  this.requiredProgramTemplate;
 }
 toJson() {
  var t = super.toJson();
  return t.emissive = this._emissive.getHex(), t.color = this._color.getHex(), t;
 }
 static fromJson(t) {
  var e = new MeshBasicMaterial();
  return (e = super.fromJson(t, e))._emissive = new Color(t.emissive), e._color = new Color(t.color), 
  e;
 }
 update(t) {
  for (var e in super.update(t), t) switch (e) {
  case "emissive":
   this._emissive = t.emissive, delete t.color;
   break;

  case "color":
   this._color = t.color, delete t.color;
  }
 }
}

let MeshPhongMaterial$1 = class MeshPhongMaterial extends Material {
 constructor() {
  super(Material), this.type = "MeshPhongMaterial", this._color = new Color(16777215 * Math.random()), 
  this._specular = new Color(16777215 * Math.random()), this._shininess = 16 * Math.random(), 
  this.programName = "phong";
 }
 set color(t) {
  this._color = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    color: this._color.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set specular(t) {
  this._specular = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    specular: this._specular.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set shininess(t) {
  this._shininess = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    shininess: this._shininess
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 get color() {
  return this._color;
 }
 get specular() {
  return this._specular;
 }
 get shininess() {
  return this._shininess;
 }
 resetProgramFlagsAndValues() {
  super.resetProgramFlagsAndValues();
 }
 requiredProgram(t = void 0) {
  return null === this.requiredProgramTemplate && (this.resetProgramFlagsAndValues(), 
  this.requiredProgramTemplate = new MaterialProgramTemplate(this.programName2, this.flags, this.values, t)), 
  this.requiredProgramTemplate;
 }
 toJson() {
  var t = super.toJson();
  return t.color = this._color.getHex(), t.specular = this._specular.getHex(), t.shininess = this._shininess, 
  t;
 }
 static fromJson(t) {
  var e = new MeshPhongMaterial$1();
  return (e = super.fromJson(t, e))._color = new Color(t.color), e._specular = new Color(t.specular), 
  e._shininess = t.shininess, e;
 }
 update(t) {
  for (var e in super.update(t), t) switch (e) {
  case "color":
   this._color.setHex(t.color), delete t.color;
   break;

  case "specular":
   this._specular.setHex(t.specular), delete t.specular;
   break;

  case "shininess":
   this._shininess = t.shininess, delete t.shininess;
  }
 }
};

class Object3D {
 constructor() {
  var t = this;
  this._uuid = _Math.generateUUID(), this.type = "Object3D", this._parent = null, 
  this._children = [], this._position = new Vector3(), this._rotation = new Euler(), 
  this._quaternion = new Quaternion(), this._scale = new Vector3(1, 1, 1), this._visible = !0, 
  this._frustumCulled = !0, this._rotation._onChange(function() {
   t.quaternion.setFromEuler(t.rotation, !1);
  }), this._quaternion._onChange(function() {
   t.rotation.setFromQuaternion(t.quaternion, void 0, !1);
  }), this._matrix = new Matrix4(), this._matrixWorld = new Matrix4(), this._matrixWorldNeedsUpdate = !1, 
  this._modelViewMatrix = new Matrix4(), this._normalMatrix = new Matrix3(), this._modelViewProjectionMatrix = new Matrix4(), 
  this._matrixAutoUpdate = !0, this._onChangeListener = null, this.rotateOnAxis = rotateOnAxis, 
  this.rotateX = rotateX, this.rotateY = rotateY, this.rotateZ = rotateZ, this.rotate = rotate, 
  this.lookAt = lookAt, this.translateOnAxis = translateOnAxis, this.translateX = translateX, 
  this.translateY = translateY, this.translateZ = translateZ, this.translate = translate, 
  this._renderOrder = 0, this._isStatic = !1, this._staticStateDirty = !0, this._renderingPrimitive = TRIANGLES, 
  this._pickable = !1, this._zVector = new Vector3(), this._boundingSphere = new Sphere(new Vector3(0, 0, 0), 1 / 0);
 }
 get parent() {
  return this._parent;
 }
 get children() {
  return this._children;
 }
 get position() {
  return this._position;
 }
 get positionX() {
  return this._position.x;
 }
 get positionY() {
  return this._position.y;
 }
 get positionZ() {
  return this._position.z;
 }
 get rotation() {
  return this._rotation;
 }
 get rotationX() {
  return this._rotation.x;
 }
 get rotationY() {
  return this._rotation.y;
 }
 get rotationZ() {
  return this._rotation.z;
 }
 get quaternion() {
  return this._quaternion;
 }
 get scale() {
  return this._scale;
 }
 get matrixAutoUpdate() {
  return this._matrixAutoUpdate;
 }
 get matrixWorld() {
  return this._matrixWorld;
 }
 get visible() {
  return this._visible;
 }
 get frustumCulled() {
  return this._frustumCulled;
 }
 get renderOrder() {
  return this._renderOrder;
 }
 get isStatic() {
  return this._isStatic;
 }
 get staticStateDirty() {
  return this._staticStateDirty;
 }
 get renderingPrimitive() {
  return this._renderingPrimitive;
 }
 get pickable() {
  return this._pickable;
 }
 get matrix() {
  return this._matrix;
 }
 set matrix(t) {
  this._matrix = t, this._matrixWorldNeedsUpdate = !0;
 }
 setMatrixFromArray(t) {
  this._matrix.fromArray(t), this._matrixWorldNeedsUpdate = !0;
 }
 get modelViewMatrix() {
  return this._modelViewMatrix;
 }
 get normalMatrix() {
  return this._normalMatrix;
 }
 get modelViewProjectionMatrix() {
  return this._modelViewProjectionMatrix;
 }
 set visible(t) {
  this._visible !== t && (this._visible = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    visible: this._visible
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set position(t) {
  t.equals(this._position) || (this._position.copy(t), this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    position: this._position.toArray()
   }
  }, this._onChangeListener.objectUpdate(t)));
 }
 set positionX(t) {
  this._position.x !== t && (this._position.x = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    position: this._position.toArray()
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set positionY(t) {
  this._position.y !== t && (this._position.y = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    position: this._position.toArray()
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set positionZ(t) {
  this._position.z !== t && (this._position.z = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    position: this._position.toArray()
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set rotation(t) {
  t.equals(this._rotation) || (this._rotation.copy(t), this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    quaternion: this._quaternion.toArray()
   }
  }, this._onChangeListener.objectUpdate(t)));
 }
 set rotationX(t) {
  this._rotation.x !== t && (this._rotation.x = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    quaternion: this._quaternion.toArray()
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set rotationY(t) {
  this._rotation.y !== t && (this._rotation.y = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    quaternion: this._quaternion.toArray()
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set rotationZ(t) {
  this._rotation.z !== t && (this._rotation.z = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    quaternion: this._quaternion.toArray()
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set quaternion(t) {
  t.equals(this._quaternion) || (this._quaternion.copy(t), this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    quaternion: this._quaternion.toArray()
   }
  }, this._onChangeListener.objectUpdate(t)));
 }
 set scale(t) {
  t.equals(this._scale) || (this._scale = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    scale: this._scale.toArray()
   }
  }, this._onChangeListener.objectUpdate(t)));
 }
 set matrixAutoUpdate(t) {
  t !== this._matrixAutoUpdate && (this._matrixAutoUpdate = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    matrixAutoUpdate: this._matrixAutoUpdate
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set frustumCulled(t) {
  t !== this._frustumCulled && (this._frustumCulled = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    frustumCulled: this._frustumCulled
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set renderOrder(t) {
  t !== this._renderOrder && (this._renderOrder = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    renderOrder: this._renderOrder
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set isStatic(t) {
  t !== this._isStatic && (this._isStatic = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    isStatic: this._isStatic
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set staticStateDirty(t) {
  t !== this._staticStateDirty && (this._staticStateDirty = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    staticStateDirty: this._staticStateDirty
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set renderingPrimitive(t) {
  t !== this._renderingPrimitive && (this._renderingPrimitive = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    renderingPrimitive: this._renderingPrimitive
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set pickable(t) {
  t !== this._pickable && (this._pickable = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    pickable: this._pickable
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set modelViewMatrix(t) {
  this._modelViewMatrix = t;
 }
 set normalMatrix(t) {
  this._normalMatrix = t;
 }
 set modelViewProjectionMatrix(t) {
  this._modelViewProjectionMatrix = t;
 }
 addOnChangeListener(t, e) {
  if (this._onChangeListener = t, e) for (var i = 0; i < this._children.length; i++) this._children[i].addOnChangeListener(t, e);
 }
 applyMatrix(t) {
  this._matrix.multiplyMatrices(t, this._matrix), this._matrix.decompose(this._position, this._quaternion, this._scale), 
  this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    position: this._position.toArray(),
    quaternion: this._quaternion.toArray(),
    scale: this._scale.toArray()
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 updateMatrix() {
  this._matrix.compose(this._position, this._quaternion, this._scale), this._matrixWorldNeedsUpdate = !0, 
  this._UPDATE_BOUNDS = !0;
 }
 updateMatrixWorld(t = !1) {
  this._matrixAutoUpdate && this.updateMatrix(), (this._matrixWorldNeedsUpdate || t) && (null === this.parent ? this._matrixWorld.copy(this._matrix) : this._matrixWorld.multiplyMatrices(this.parent._matrixWorld, this._matrix), 
  this._matrixWorldNeedsUpdate = !1, this._UPDATE_BOUNDS = t = !0);
  for (var e = 0; e < this._children.length; e++) this._children[e].updateMatrixWorld(t);
 }
 updateWorldMatrix(t, e) {
  var i = this.parent;
  if (!0 === t && null !== i && i.updateWorldMatrix(!0, !1), this.matrixAutoUpdate && this.updateMatrix(), 
  null === this.parent ? this.matrixWorld.copy(this._matrix) : this.matrixWorld.multiplyMatrices(this.parent.matrixWorld, this._matrix), 
  (this._UPDATE_BOUNDS = !0) === e) for (var r = this.children, s = r.length; 0 < s; ) r[0].updateWorldMatrix(!1, !0);
 }
 add(t) {
  t !== this && (null !== t._parent && t._parent.remove(t), (t._parent = this)._children.push(t), 
  this._onChangeListener) && (t.onChangeListener = this._onChangeListener, t = {
   uuid: t._uuid,
   changes: {
    parentUuid: this._uuid,
    objectRef: t
   }
  }, this._onChangeListener.hierarchyUpdate(t));
 }
 remove(t) {
  var e = this._children.indexOf(t);
  -1 !== e && (t._parent = null, this._children.splice(e, 1), this._onChangeListener) && (e = {
   uuid: t._uuid,
   changes: {
    parentUuid: null,
    objectRef: t
   }
  }, this._onChangeListener.hierarchyUpdate(e));
 }
 clear() {
  let e = this;
  this._children = this._children.filter(function(t) {
   return e._onChangeListener && (t = {
    uuid: t._uuid,
    changes: {
     parentUuid: null,
     objectRef: t
    }
   }, e._onChangeListener.hierarchyUpdate(t)), !1;
  });
 }
 traverse(i) {
  i(this);
  for (let t = 0, e = this._children.length; t < e; t++) this._children[t].traverse(i);
 }
 raycast() {}
 computeBoundingSphere() {
  let e = [];
  return this.traverse(function(t) {
   t instanceof Mesh && null != t.geometry && (t = t.geometry.boundingSphere, !isNaN(t.radius)) && 0 < t.radius && e.push(t);
  }), 0 < e.length ? _Math.computeSpheresBoundingSphere(e) : new Sphere();
 }
 toJson() {
  var t = {};
  return t.uuid = this._uuid, t.type = this.type, this._parent && (t.parentUuid = this._parent._uuid), 
  t.position = this._position.toArray(), t.quaternion = this._quaternion.toArray(), 
  t.scale = this._scale.toArray(), t.visible = this._visible, t.frustumCulled = this._frustumCulled, 
  t.matrixAutoUpdate = this._matrixAutoUpdate, t;
 }
 static fromJson(t, e) {
  return (e = e || new Object3D())._uuid = t.uuid, e._position.fromArray(t.position), 
  e._quaternion.fromArray(t.quaternion), e._scale.fromArray(t.scale), e._visible = t.visible, 
  e._frustumCulled = t.frustumCulled, e._matrixWorldNeedsUpdate = !0, e._matrixAutoUpdate = t.matrixAutoUpdate, 
  e;
 }
 static importHierarchy(t, e, i) {
  var r, s = {};
  for (r of Object.keys(t)) switch ((u = t[r]).type) {
  case "Mesh":
  case "Circle":
  case "Quad":
  case "Line":
   var a = e[u.geometryUuid], n = i[u.materialUuid];
   if (a ? a = Geometry.fromJson(a) : (a = void 0, console.warn("Could not find geometry for the mesh: " + u.uuid)), 
   n) switch (n.type) {
   case "Material":
    n = Material.fromJson(n);
    break;

   case "MeshBasicMaterial":
    n = MeshBasicMaterial.fromJson(n);
    break;

   case "MeshPhongMaterial":
    n = MeshPhongMaterial$1.fromJson(n);
    break;

   default:
    n = void 0;
   } else n = void 0, console.warn("Could not find material for the mesh: " + u.uuid);
   s[u.uuid] = Mesh.fromJson(u, a, n);
   break;

  default:
   s[u.uuid] = RC[u.type].fromJson(u);
  }
  var o, h = [];
  for (o of Object.keys(t)) {
   var u = s[o], l = t[o].parentUuid;
   (l && (l = s[l]) ? (u._parent = l).children : h).push(u);
  }
  return h;
 }
 exportHierarchy(t, e) {
  t.objects && t.geometries && t.materials || (t.objects = {}, t.geometries = {}, 
  t.materials = {});
  var i = this.toJson();
  e || delete i.parentUuid, t.objects[i.uuid] = i, "Mesh" !== this.type && "Quad" !== this.type && "Circle" !== this.type && "Line" !== this.type || (t.geometries[this._geometry._uuid] = this._geometry.toJson(), 
  t.materials[this._material._uuid] = this._material.toJson());
  for (var r = 0; r < this.children.length; r++) this._children[r].exportHierarchy(t, !0);
 }
 update(t) {
  for (var e in t) switch (e) {
  case "position":
   this._position.fromArray(t.position), delete t.position;
   break;

  case "quaternion":
   this._quaternion.fromArray(t.quaternion), delete t.quaternion;
   break;

  case "scale":
   this._scale.fromArray(t.scale), delete t.scale;
   break;

  case "visible":
   this._visible = t.visible, delete t.visible;
   break;

  case "frustumCulled":
   this._frustumCulled = t.frustumCulled, delete t.frustumCulled;
   break;

  case "matrixAutoUpdate":
   this._matrixAutoUpdate = t.matrixAutoUpdate, delete t.matrixAutoUpdate;
  }
 }
 fillRenderArray(t) {
  throw console.warn("-----------------------------------------------"), console.warn(this), 
  console.warn("Object has missing method: fillRenderArray"), console.warn("-----------------------------------------------"), 
  new Error("Not implemented");
 }
 project(t) {
  throw console.warn("-----------------------------------------------"), console.warn(this), 
  console.warn("Object has missing method: project missing"), console.warn("-----------------------------------------------"), 
  new Error("Not implemented");
 }
 getRequiredPrograms(t) {
  throw console.warn("-----------------------------------------------"), console.warn(this), 
  console.warn("Object has missing method: getRequiredPrograms"), console.warn("-----------------------------------------------"), 
  new Error("Not implemented");
 }
 update(t, e) {
  throw console.warn("-----------------------------------------------"), console.warn(this), 
  console.warn("Object has missing method: update"), console.warn("-----------------------------------------------"), 
  new Error("Not implemented");
 }
 get boundingSphere() {
  return this._geometry ? this._geometry.boundingSphere : this._boundingSphere;
 }
}

let rotateOnAxis = function() {
 let i = new Quaternion();
 return function(t, e) {
  if (0 !== e) return i.setFromAxisAngle(t, e), this._quaternion.multiply(i), this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    quaternion: this._quaternion.toArray()
   }
  }, this._onChangeListener.objectUpdate(t)), this;
 };
}(), rotateX = function() {
 let e = new Vector3(1, 0, 0);
 return function(t) {
  return this.rotateOnAxis(e, t);
 };
}(), rotateY = function() {
 var e = new Vector3(0, 1, 0);
 return function(t) {
  return this.rotateOnAxis(e, t);
 };
}(), rotateZ = function() {
 var e = new Vector3(0, 0, 1);
 return function(t) {
  return this.rotateOnAxis(e, t);
 };
}(), rotate = function(t) {
 this.rotateX(t.x), this.rotateY(t.y), this.rotateZ(t.z);
}, lookAt = function() {
 let i = new Matrix4(), r = new Quaternion();
 return function(t, e) {
  i.lookAt(this._position, t, e), r.setFromRotationMatrix(i), r.equals(this._quaternion) || (this._quaternion.copy(r), 
  this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    quaternion: this._quaternion.toArray()
   }
  }, this._onChangeListener.objectUpdate(t)));
 };
}(), translateOnAxis = function() {
 let i = new Vector3();
 return function(t, e) {
  return 0 !== e && (i.copy(t).applyQuaternion(this._quaternion), this._position.add(i.multiplyScalar(e)), 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    position: this._position.toArray()
   }
  }, this._onChangeListener.objectUpdate(t)), this;
 };
}(), translateX = function() {
 let e = new Vector3(1, 0, 0);
 return function(t) {
  return this.translateOnAxis(e, t);
 };
}(), translateY = function() {
 let e = new Vector3(0, 1, 0);
 return function(t) {
  return this.translateOnAxis(e, t);
 };
}(), translateZ = function() {
 let e = new Vector3(0, 0, 1);
 return function(t) {
  return this.translateOnAxis(e, t);
 };
}(), translate = function(t) {
 this.translateX(t.x), this.translateY(t.y), this.translateZ(t.z);
};

class CustomShaderMaterial extends Material {
 constructor(t, e = {}, i = {}) {
  super(Material), this.type = "CustomShaderMaterial", this._uniforms = e, this._attributes = i, 
  this._flagsSB = [], this._valuesSB = {}, this.programName = "custom_" + t;
 }
 addSBFlag(t) {
  this._flagsSB.push(t);
 }
 rmSBFlag(t) {
  t = this._flagsSB.indexOf(t);
  -1 < t && this._flagsSB.splice(t, 1);
 }
 clearSBFlags() {
  this._flagsSB.clear();
 }
 addSBValue(t, e) {
  this._valuesSB[t] = e;
 }
 rmSBValue(t) {
  delete this._valuesSB[t];
 }
 clearSBValues() {
  this._valuesSB = {};
 }
 setUniform(t, e) {
  this._uniforms[t] = e;
 }
 removeUniform(t) {
  delete this._uniforms[t];
 }
 getUniform(t) {
  return this._uniforms[t];
 }
 setAttribute(t, e) {
  this._attributes[t] = e;
 }
 removeAttribute(t) {
  delete this._attributes[t];
 }
 getAttribute(t) {
  return this._attributes[t];
 }
 resetProgramFlagsAndValues() {
  super.resetProgramFlagsAndValues();
  for (let t = 0; t < this._flagsSB.length; t++) this.flags.push(this._flagsSB[t]);
  for (var t in this._valuesSB) this._valuesSB.hasOwnProperty(t) && (this.values[t] = this._valuesSB[t]);
 }
 requiredProgram(t = void 0, e = !1) {
  if (!e) return null === this.requiredProgramTemplate && (this.resetProgramFlagsAndValues(), 
  this.requiredProgramTemplate = new MaterialProgramTemplate(this.programName2, this.flags, this.values, t)), 
  this.requiredProgramTemplate;
  console.warn("THIS SEGMENT IS DEPRECATED"), this.resetProgramFlagsAndValues();
 }
}

class PickingShaderMaterial extends CustomShaderMaterial {
 static PICK_MODE = {
  RGB: 0,
  UINT: 1
 };
 static DEFAULT_PICK_MODE = PickingShaderMaterial.PICK_MODE.RGB;
 constructor(t = "TRIANGLES", e = {}, i = {}, r = {}) {
  super("picker_" + t, e, i, r), this.type = "PickingShaderMaterial", this._pickMode = null, 
  this.pickMode = r.mode || PickingShaderMaterial.DEFAULT_PICK_MODE;
 }
 get pickMode() {
  return this._pickMode;
 }
 set pickMode(t) {
  t !== this._pickMode && (this.requiredProgramTemplate = null, (this._pickMode = t) === PickingShaderMaterial.PICK_MODE.RGB ? (this.removeUniform("u_PickInstance"), 
  this.rmSBFlag("PICK_MODE_UINT"), this.addSBFlag("PICK_MODE_RGB")) : t === PickingShaderMaterial.PICK_MODE.UINT ? (this.rmSBFlag("PICK_MODE_RGB"), 
  this.addSBFlag("PICK_MODE_UINT"), this.setUniform("u_PickInstance", !1)) : console.error("Unknown pick mode: [" + t + "]."), 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    pickMode: this._pickMode
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 resetProgramFlagsAndValues() {
  super.resetProgramFlagsAndValues();
 }
 requiredProgram(t = void 0) {
  return null === this.requiredProgramTemplate && (this.resetProgramFlagsAndValues(), 
  this.requiredProgramTemplate = new MaterialProgramTemplate(this.programName, this.flags, this.values, t)), 
  this.requiredProgramTemplate;
 }
}

class Mesh extends Object3D {
 static sDefaultPickable = !1;
 constructor(t, e, i, r, s = {}) {
  super(Object3D), this.type = "Mesh", this._geometry = void 0 !== t ? t : new Geometry(), 
  this._material = void 0 !== e ? e : new MeshBasicMaterial({
   color: 16777215 * Math.random()
  }), this._pickingMaterial = i, this._outlineMaterial = r, this.GBufferMaterial = s.GBufferMaterial, 
  this.raycast = _raycast, this._RGB_ID = new Color(0, 0, 0), this._UINT_ID = 0, 
  this._drawOutline = !1, this._instanced = !1, this._instancedTranslation = !1, 
  this._instanceCount = 1, this.pickable = Mesh.sDefaultPickable;
 }
 addOnChangeListener(t, e) {
  this._material.onChangeListener = t, this._geometry.onChangeListener = t, super.addOnChangeListener(t, e);
 }
 get material() {
  return this._material;
 }
 get pickingMaterial() {
  return this._pickingMaterial;
 }
 get outlineMaterial() {
  return this._outlineMaterial;
 }
 get geometry() {
  return this._geometry;
 }
 get RGB_ID() {
  return this._RGB_ID;
 }
 get UINT_ID() {
  return this._UINT_ID;
 }
 get drawOutline() {
  return this._drawOutline;
 }
 get pickable() {
  return super.pickable;
 }
 get instanced() {
  return this._instanced;
 }
 get instancedTranslation() {
  return this._instancedTranslation;
 }
 get instanceCount() {
  return this._instanceCount;
 }
 set material(t) {
  this._material = t, this._staticStateDirty = !0, this._material.instanced = this._instanced, 
  this._material.instancedTranslation = this._instancedTranslation;
 }
 set pickingMaterial(t) {
  this._pickingMaterial = t, this._staticStateDirty = !0, this._pickingMaterial.instanced = this._instanced, 
  this._pickingMaterial.instancedTranslation = this._instancedTranslation;
 }
 set outlineMaterial(t) {
  this._outlineMaterial = t, this._staticStateDirty = !0, this._outlineMaterial.instanced = this._instanced;
 }
 get GBufferMaterial() {
  return void 0 === this._GBufferMaterial && (this.GBufferMaterial = new CustomShaderMaterial("multi")), 
  this._GBufferMaterial;
 }
 set GBufferMaterial(t) {
  this._GBufferMaterial = t, this._staticStateDirty = !0;
 }
 set geometry(t) {
  this._geometry = t;
 }
 set onChangeListener(t) {
  super.onChangeListener = t, this._geometry.onChangeListener = t, this._material.onChangeListener = t;
 }
 set RGB_ID(t) {
  this._RGB_ID = t;
 }
 set UINT_ID(t) {
  this._UINT_ID = t;
 }
 set drawOutline(t) {
  this._drawOutline = t;
 }
 set pickable(t) {
  (super.pickable = t) && !this._pickingMaterial && (this.pickingMaterial = new PickingShaderMaterial("TRIANGLES"), 
  this.pickingMaterial.side = this.material.side);
 }
 set instanced(t) {
  this._instanced = t, this._material.instanced = t, this._pickingMaterial && (this._pickingMaterial.instanced = t), 
  this._outlineMaterial && (this._outlineMaterial.instanced = t);
 }
 set instancedTranslation(t) {
  this._instanced = t, this._material.instancedTranslation = t, this._pickingMaterial && (this._pickingMaterial.instancedTranslation = t), 
  this._outlineMaterial && (this._outlineMaterial.instancedTranslation = t);
 }
 set instanceCount(t) {
  this._instanceCount = t;
 }
 toJson() {
  var t = super.toJson();
  return t.geometryUuid = this._geometry._uuid, t.materialUuid = this._material._uuid, 
  t;
 }
 static fromJson(t, e, i, r) {
  return r = r || new Mesh(e, i), r = super.fromJson(t, r);
 }
 fillRenderArray(t) {
  (this.material.transparent ? t.transparentObjects : t.opaqueObjects).addlast(this);
 }
 project(t) {
  this.material.transparent && (this._zVector.setFromMatrixPosition(this.matrixWorld), 
  this._zVector.applyMatrix4(t));
 }
 getRequiredPrograms(t) {
  var e = [ this._material.requiredProgram(t) ];
  return this._pickingMaterial && this.pickable && e.push(this._pickingMaterial.requiredProgram(t)), 
  this._outlineMaterial && this.drawOutline && e.push(this._outlineMaterial.requiredProgram(t)), 
  3 == t._renderMode && e.push(this.GBufferMaterial.requiredProgram(t)), this._staticStateDirty = !1, 
  e;
 }
 update(t, e) {
  this.modelViewMatrix.multiplyMatrices(e.matrixWorldInverse, this._matrixWorld), 
  this.normalMatrix.getNormalMatrix(this._modelViewMatrix);
 }
 draw(t, e, i = 0) {
  var r;
  this.geometry.drawWireframe ? (r = e.getGLBuffer(this.geometry.wireframeIndices), 
  t.bindBuffer(t.ELEMENT_ARRAY_BUFFER, r), this._instanced || this._instancedTranslation ? (i = i || this._instanceCount, 
  t.drawElementsInstanced(t.LINES, this.geometry.wireframeIndices.count(), t.UNSIGNED_INT, 0, i)) : t.drawElements(t.LINES, this.geometry.wireframeIndices.count(), t.UNSIGNED_INT, 0)) : this.geometry.indices ? (r = e.getGLBuffer(this.geometry.indices), 
  t.bindBuffer(t.ELEMENT_ARRAY_BUFFER, r), this._instanced || this._instancedTranslation ? (i = i || this._instanceCount, 
  t.drawElementsInstanced(this.renderingPrimitive, this.geometry.indexCount, t.UNSIGNED_INT, 4 * this.geometry.indexStart, i)) : t.drawElements(this.renderingPrimitive, this.geometry.indexCount, t.UNSIGNED_INT, 4 * this.geometry.indexStart)) : this._instanced || this._instancedTranslation ? (i = i || this._instanceCount, 
  t.drawArraysInstanced(this.renderingPrimitive, 0, this.geometry.vertices.count(), i)) : t.drawArrays(this.renderingPrimitive, 0, this.geometry.vertices.count());
 }
}

let _raycast = function() {
 let h = new Vector3(), u = new Vector3(), l = new Vector3(), i = new Matrix4(), _ = new Ray(), r = new Sphere(), c = new Vector3(), d = new Vector3();
 function m(t, e, i, r, s, a, n) {
  h.fromArray(r.array, 3 * s), u.fromArray(r.array, 3 * a), l.fromArray(r.array, 3 * n);
  let o;
  s = t.material;
  if (null === (o = s.side === BACK_SIDE ? i.intersectTriangle(l, u, h, !0, c) : i.intersectTriangle(h, u, l, s.side !== FRONT_AND_BACK_SIDE, c))) return null;
  d.copy(c), d.applyMatrix4(t.matrixWorld);
  a = e.ray.origin.distanceTo(d);
  return a < e.near || a > e.far ? null : {
   distance: a,
   point: d.clone(),
   triangle: [ h.applyMatrix4(t.matrixWorld).clone(), u.applyMatrix4(t.matrixWorld).clone(), l.applyMatrix4(t.matrixWorld).clone() ],
   object: t
  };
 }
 return function(a, n) {
  var o = this.geometry, t = this.material, e = this.matrixWorld;
  if (void 0 !== t && void 0 !== o && (null === o.boundingSphere && o.computeBoundingSphere(), 
  r.copy(o.boundingSphere), r.applyMatrix4(e), !1 !== a.ray.intersectsSphere(r)) && (i.getInverse(e), 
  _.copy(a.ray).applyMatrix4(i), null === o.boundingBox || !1 !== _.intersectsBox(o.boundingBox))) {
   let e, i, r, s;
   var h = o.indices, u = o.vertices;
   if (null !== h) for (let t = 0; t < h.array.length; t += 3) i = h[t], r = h[t + 1], 
   s = h[t + 2], (e = m(this, a, _, u, i, r, s)) && (e.faceIndex = Math.floor(t / 3), 
   n.push(e)); else for (let t = 0; t < o.vertices.array.length; t += 9) i = t / 3, 
   r = i + 1, s = i + 2, (e = m(this, a, _, u, i, r, s)) && (e.index = i, n.push(e));
  }
 };
}();

class Line extends Mesh {
 constructor(t, e) {
  super(t, e = void 0 === e ? new MeshBasicMaterial() : e), this.type = "Line", 
  this.renderingPrimitive = LINE_STRIP;
 }
 setPoints(t) {
  void 0 === this._geometry && (this._geometry = new Geometry()), this._geometry.vertices.array = new Float32Array(t);
 }
 static fromJson(t, e, i) {
  e = new Line(e, i);
  return super.fromJson(t, void 0, void 0, e);
 }
}

function Interpolant(t, e, i, r) {
 this.parameterPositions = t, this._cachedIndex = 0, this.resultBuffer = void 0 !== r ? r : new e.constructor(i), 
 this.sampleValues = e, this.valueSize = i;
}

function QuaternionLinearInterpolant(t, e, i, r) {
 Interpolant.call(this, t, e, i, r);
}

function LinearInterpolant(t, e, i, r) {
 Interpolant.call(this, t, e, i, r);
}

function DiscreteInterpolant(t, e, i, r) {
 Interpolant.call(this, t, e, i, r);
}

function CubicInterpolant(t, e, i, r) {
 Interpolant.call(this, t, e, i, r), this._weightPrev = -0, this._offsetPrev = -0, 
 this._weightNext = -0, this._offsetNext = -0;
}

function SphericalHarmonics3() {
 this.coefficients = [];
 for (var t = 0; t < 9; t++) this.coefficients.push(new Vector3());
}

Object.assign(Interpolant.prototype, {
 evaluate: function(t) {
  var e, i = this.parameterPositions, r = this._cachedIndex, s = i[r], a = i[r - 1];
  t: {
   e: {
    i: {
     r: if (!(t < s)) {
      for (var n = r + 2; ;) {
       if (void 0 === s) {
        if (t < a) break r;
        return r = i.length, this._cachedIndex = r, this.afterEnd_(r - 1, t, a);
       }
       if (r === n) break;
       if (a = s, t < (s = i[++r])) break e;
      }
      e = i.length;
      break i;
     }
     if (a <= t) break t;
     var o = i[1];
     t < o && (r = 2, a = o);
     for (n = r - 2; ;) {
      if (void 0 === a) return this._cachedIndex = 0, this.beforeStart_(0, t, s);
      if (r === n) break;
      if (s = a, (a = i[--r - 1]) <= t) break e;
     }
     e = r, r = 0;
    }
    for (;r < e; ) {
     var h = r + e >>> 1;
     t < i[h] ? e = h : r = 1 + h;
    }
    if (s = i[r], void 0 === (a = i[r - 1])) return this._cachedIndex = 0, this.beforeStart_(0, t, s);
    if (void 0 === s) return r = i.length, this._cachedIndex = r, this.afterEnd_(r - 1, a, t);
   }
   this._cachedIndex = r, this.intervalChanged_(r, a, s);
  }
  return this.interpolate_(r, a, t, s);
 },
 settings: null,
 DefaultSettings_: {},
 getSettings_: function() {
  return this.settings || this.DefaultSettings_;
 },
 copySampleValue_: function(t) {
  for (var e = this.resultBuffer, i = this.sampleValues, r = this.valueSize, s = t * r, a = 0; a !== r; ++a) e[a] = i[s + a];
  return e;
 },
 interpolate_: function() {
  throw new Error("call to abstract method");
 },
 intervalChanged_: function() {}
}), Object.assign(Interpolant.prototype, {
 beforeStart_: Interpolant.prototype.copySampleValue_,
 afterEnd_: Interpolant.prototype.copySampleValue_
}), QuaternionLinearInterpolant.prototype = Object.assign(Object.create(Interpolant.prototype), {
 constructor: QuaternionLinearInterpolant,
 interpolate_: function(t, e, i, r) {
  for (var s = this.resultBuffer, a = this.sampleValues, n = this.valueSize, o = t * n, h = (i - e) / (r - e), u = o + n; o !== u; o += 4) Quaternion.slerpFlat(s, 0, a, o - n, a, o, h);
  return s;
 }
}), LinearInterpolant.prototype = Object.assign(Object.create(Interpolant.prototype), {
 constructor: LinearInterpolant,
 interpolate_: function(t, e, i, r) {
  for (var s = this.resultBuffer, a = this.sampleValues, n = this.valueSize, o = t * n, h = o - n, u = (i - e) / (r - e), l = 1 - u, _ = 0; _ !== n; ++_) s[_] = a[h + _] * l + a[o + _] * u;
  return s;
 }
}), DiscreteInterpolant.prototype = Object.assign(Object.create(Interpolant.prototype), {
 constructor: DiscreteInterpolant,
 interpolate_: function(t) {
  return this.copySampleValue_(t - 1);
 }
}), CubicInterpolant.prototype = Object.assign(Object.create(Interpolant.prototype), {
 constructor: CubicInterpolant,
 DefaultSettings_: {
  endingStart: ZeroCurvatureEnding,
  endingEnd: ZeroCurvatureEnding
 },
 intervalChanged_: function(t, e, i) {
  var r = this.parameterPositions, s = t - 2, a = t + 1, n = r[s], o = r[a];
  if (void 0 === n) switch (this.getSettings_().endingStart) {
  case ZeroSlopeEnding:
   s = t, n = 2 * e - i;
   break;

  case WrapAroundEnding:
   n = e + r[s = r.length - 2] - r[s + 1];
   break;

  default:
   s = t, n = i;
  }
  if (void 0 === o) switch (this.getSettings_().endingEnd) {
  case ZeroSlopeEnding:
   a = t, o = 2 * i - e;
   break;

  case WrapAroundEnding:
   o = i + r[a = 1] - r[0];
   break;

  default:
   a = t - 1, o = e;
  }
  var h = .5 * (i - e), u = this.valueSize;
  this._weightPrev = h / (e - n), this._weightNext = h / (o - i), this._offsetPrev = s * u, 
  this._offsetNext = a * u;
 },
 interpolate_: function(t, e, i, r) {
  for (var s = this.resultBuffer, a = this.sampleValues, n = this.valueSize, o = t * n, h = o - n, u = this._offsetPrev, l = this._offsetNext, t = this._weightPrev, _ = this._weightNext, i = (i - e) / (r - e), r = i * i, e = r * i, c = -t * e + 2 * t * r - t * i, d = (1 + t) * e + (-1.5 - 2 * t) * r + (-.5 + t) * i + 1, m = (-1 - _) * e + (1.5 + _) * r + .5 * i, g = _ * e - _ * r, p = 0; p !== n; ++p) s[p] = c * a[u + p] + d * a[h + p] + m * a[o + p] + g * a[l + p];
  return s;
 }
}), Object.assign(SphericalHarmonics3.prototype, {
 isSphericalHarmonics3: !0,
 set: function(t) {
  for (var e = 0; e < 9; e++) this.coefficients[e].copy(t[e]);
  return this;
 },
 zero: function() {
  for (var t = 0; t < 9; t++) this.coefficients[t].set(0, 0, 0);
  return this;
 },
 getAt: function(t, e) {
  var i = t.x, r = t.y, t = t.z, s = this.coefficients;
  return e.copy(s[0]).multiplyScalar(.282095), e.addScale(s[1], .488603 * r), e.addScale(s[2], .488603 * t), 
  e.addScale(s[3], .488603 * i), e.addScale(s[4], i * r * 1.092548), e.addScale(s[5], r * t * 1.092548), 
  e.addScale(s[6], .315392 * (3 * t * t - 1)), e.addScale(s[7], i * t * 1.092548), 
  e.addScale(s[8], .546274 * (i * i - r * r)), e;
 },
 getIrradianceAt: function(t, e) {
  var i = t.x, r = t.y, t = t.z, s = this.coefficients;
  return e.copy(s[0]).multiplyScalar(.886227), e.addScale(s[1], 1.023328 * r), e.addScale(s[2], 1.023328 * t), 
  e.addScale(s[3], 1.023328 * i), e.addScale(s[4], .858086 * i * r), e.addScale(s[5], .858086 * r * t), 
  e.addScale(s[6], .743125 * t * t - .247708), e.addScale(s[7], .858086 * i * t), 
  e.addScale(s[8], .429043 * (i * i - r * r)), e;
 },
 add: function(t) {
  for (var e = 0; e < 9; e++) this.coefficients[e].add(t.coefficients[e]);
  return this;
 },
 scale: function(t) {
  for (var e = 0; e < 9; e++) this.coefficients[e].multiplyScalar(t);
  return this;
 },
 lerp: function(t, e) {
  for (var i = 0; i < 9; i++) this.coefficients[i].lerp(t.coefficients[i], e);
  return this;
 },
 equals: function(t) {
  for (var e = 0; e < 9; e++) if (!this.coefficients[e].equals(t.coefficients[e])) return !1;
  return !0;
 },
 copy: function(t) {
  return this.set(t.coefficients);
 },
 clone: function() {
  return new this.constructor().copy(this);
 },
 fromArray: function(t, e) {
  void 0 === e && (e = 0);
  for (var i = this.coefficients, r = 0; r < 9; r++) i[r].fromArray(t, e + 3 * r);
  return this;
 },
 toArray: function(t, e) {
  void 0 === t && (t = []), void 0 === e && (e = 0);
  for (var i = this.coefficients, r = 0; r < 9; r++) i[r].toArray(t, e + 3 * r);
  return t;
 }
}), Object.assign(SphericalHarmonics3, {
 getBasisAt: function(t, e) {
  var i = t.x, r = t.y, t = t.z;
  e[0] = .282095, e[1] = .488603 * r, e[2] = .488603 * t, e[3] = .488603 * i, e[4] = 1.092548 * i * r, 
  e[5] = 1.092548 * r * t, e[6] = .315392 * (3 * t * t - 1), e[7] = 1.092548 * i * t, 
  e[8] = .546274 * (i * i - r * r);
 }
});

class XHRStreamer {
 constructor(t = new LoadingManager(), e = "", i) {
  this._manager = t, this._responseType = e, this._chunkSize = i, this._size = 0, 
  this._position = 0, this._chunkSizeDownlaoded = 0;
 }
 load(e, i, r, s, a, n, o) {
  const h = this;
  this.get_fileSize(e, function(t) {
   h._size = t, n({
    size: h._size,
    type: "bytes"
   }), h.get_fileData(h, e, i, r, s, a, o);
  });
 }
 get_fileSize(t, e) {
  const i = new XMLHttpRequest();
  i.onreadystatechange = function(t) {
   this.readyState === this.DONE && e(parseInt(i.getResponseHeader("Content-Length")));
  }, i.open("HEAD", t, !0), i.send();
 }
 get_fileData(i, r, s, e, a, n, o) {
  const h = new XMLHttpRequest();
  h.responseType = this._responseType, h.onreadystatechange = function(t) {
   this.readyState !== this.LOADING && (this.readyState, this.DONE);
  }, h.onprogress = function(t) {
   e(t);
  }, h.onload = function(t) {
   var e;
   206 === this.status ? (i._position += i._chunkSize, e = h.response, i._position < i._size ? (o(e), 
   h.open("GET", r, !0), h.setRequestHeader("Range", "bytes=" + i._position + "-" + (i._position + i._chunkSize - 1)), 
   h.send()) : (i._manager.itemEnd(r), o(e), s(t))) : i._manager.itemError(r);
  }, h.onerror = function(t) {
   a(t), i._manager.itemError(r);
  }, h.onabort = function(t) {
   n(t);
  }, h.open("GET", r, !0), h.setRequestHeader("Range", "bytes=" + this._position + "-" + (this._position + this._chunkSize - 1)), 
  h.send(), this._manager.itemStart(r);
 }
}

class LASLoader {
 constructor(t = new LoadingManager(), e = "", i = !0, r = 1048576) {
  this._manager = t, this._responseType = e, this._stream = i, this._chunkSize = r, 
  this.PHBLoaded = !1, this.VLRsLoaded = !1, this.PDRLoaded = !1, this.PointsLoaded = 0, 
  this.PHB = null, this.DataBuffer = null, this.DataView = null, this.LASSize = 0, 
  this.LASLoaded = 0, this.LASChunk = 0, this.output = {};
 }
 load(t, e, i, r, s, a, n, o) {
  this._loadStream(t, e, i, r, s, a, n, o);
 }
 _loadStream(t, i, e, r, s, a, n, o) {
  const h = this;
  new XHRStreamer(this._manager, this._responseType, this._chunkSize).load(t, function(t) {
   e(t), h.output = {};
  }, function(t) {
   h.LASChunk = t.total, r(t);
  }, s, a, function(t) {
   h.LASSize = t.size, h.DataBuffer = new ArrayBuffer(t.size), h.DataView = new DataView(h.DataBuffer), 
   h.PHB = new LASLoader.PHB(), n(t);
  }, function(t) {
   var e = null;
   h._copyArray(h.DataBuffer, t, 0, h.LASLoaded, h.LASChunk), h.LASLoaded += h.LASChunk, 
   !1 === h.PHBLoaded && (h.PHBLoaded = h._parseHeader(h.DataView, h.LASLoaded, h.PHB), 
   h.PHBLoaded) && (console.log("PHB is loaded"), h._printHeader(h.PHB), 0 === h.PHB.inserts.NUMBER_OF_VARIABLE_LENGTH_RECORDS.data) && (h.VLRsLoaded = !0), 
   !0 === h.PHBLoaded && h.VLRsLoaded, null != (e = !0 === h.PHBLoaded && !1 === h.PDRLoaded ? h._parsePointData(h.DataView, h.LASLoaded, i) : e) && o(e);
  });
 }
 _parsePointData(r, t, s) {
  let e = this.PHB.inserts.LEGACY_NUMBER_OF_POINT_RECORDS.data;
  -1 === e && (e = this.PHB.inserts.NUMBER_OF_POINT_RECORDS.data);
  var a = this.PHB.inserts.POINT_DATA_RECORD_LENGTH.data, n = this._generateFormat(this.PHB.inserts.POINT_DATA_RECORD_FORMAT.data), o = this.PHB.inserts.OFFSET_TO_POINT_DATA.data, h = this.PHB.inserts.X_OFFSET.data, u = this.PHB.inserts.Y_OFFSET.data, l = this.PHB.inserts.Z_OFFSET.data, _ = this.PHB.inserts.X_SCALE_FACTOR.data, c = this.PHB.inserts.Y_SCALE_FACTOR.data, d = this.PHB.inserts.Z_SCALE_FACTOR.data, m = null;
  for (let i = this.PointsLoaded; i < e; i++) {
   var g = o + a * i;
   if (t <= g + a) break;
   for (let e = 0; e < s.length; e++) {
    let t = this._readFromDataView(r, n.inserts[s[e]], g);
    switch (s[e]) {
    case LASLoader.PDRFormat0.Keys.X:
     t = t * _ + h;
     break;

    case LASLoader.PDRFormat0.Keys.Y:
     t = t * c + u;
     break;

    case LASLoader.PDRFormat0.Keys.Z:
     t = t * d + l;
    }
    void 0 === (m = null == m ? {} : m)[s[e]] && (m[s[e]] = new Array()), m[s[e]][i] = t;
   }
   this.PointsLoaded++;
  }
  return m;
 }
 _generateFormat(t) {
  let e = null;
  switch (t) {
  case 0:
   e = new LASLoader.PDRFormat0();
   break;

  case 1:
   e = new LASLoader.PDRFormat1();
   break;

  case 2:
   e = new LASLoader.PDRFormat2();
   break;

  case 3:
   e = new LASLoader.PDRFormat3();
   break;

  case 4:
   e = new LASLoader.PDRFormat4();
   break;

  case 5:
   e = new LASLoader.PDRFormat5();
   break;

  case 6:
   e = new LASLoader.PDRFormat6();
   break;

  case 7:
   e = new LASLoader.PDRFormat7();
   break;

  case 8:
   e = new LASLoader.PDRFormat8();
   break;

  case 9:
   e = new LASLoader.PDRFormat9();
   break;

  case 10:
   e = new LASLoader.PDRFormat10();
   break;

  default:
   console.error("Unknown LAS format: " + t);
  }
  return e;
 }
 _copyArray(t, e, i, r, s) {
  t = new Uint8Array(t), e = new Uint8Array(e, i, s);
  t.set(e, r);
 }
 _readFromArrayBuffer(t, e, i) {
  var r = new ArrayBuffer(i), s = new Uint8Array(t), a = new Uint8Array(r);
  for (let t = 0; t < i; t++) a[t] = s[e + t];
  return r;
 }
 _parseHeader(t, e, i) {
  for (var r in console.log("Trying to parse header with " + e + " bytes loaded"), 
  i.inserts) if (i.inserts.hasOwnProperty(r) && !i.inserts[r].hasData) {
   if (i.inserts[r].endOffset > e && 1 == i.inserts[r].required) return console.log("property " + r + " requires " + i.inserts[r].endOffset + " bytes"), 
   !1;
   i.inserts[r].data = this._readFromDataView(t, i.inserts[r]), console.log("Read " + r + ": " + i.inserts[r].data);
  }
  return !0;
 }
 _printHeader(t) {
  for (var e in t.inserts) t.inserts.hasOwnProperty(e) && console.log(e + ": " + t.inserts[e].data);
 }
 _readFromDataView(t, e, i = 0) {
  var r = i + e.offset;
  switch (e.format.type) {
  case "char":
   return this._typedArray2String(new Int8Array(t.buffer, r, e.size));

  case "unsigned char":
   return this._typedArray2String(new Uint8Array(t.buffer, r, e.size));

  case "unsigned int8":
   return t.getUint8(r);

  case "short":
   return t.getInt16(r, !0);

  case "unsigned short":
   return t.getUint16(r, !0);

  case "long":
   return t.getInt32(r, !0);

  case "unsigned long":
   return t.getUint32(r, !0);

  case "long long":
   return t.getBigInt64(r, !0);

  case "unsigned long long":
   return t.getBigUint64(r, !0);

  case "float":
   return t.getFloat32(r, !0);

  case "double":
   return t.getFloat64(r, !0);

  default:
   console.error("Unknown LAZ insert format type.");
  }
 }
 _typedArray2String(t) {
  return String.fromCharCode.apply(null, t);
 }
}

LASLoader.DataTypes = {
 char: {
  type: "char",
  byteSize: 1
 },
 unsignedChar: {
  type: "unsigned char",
  byteSize: 1
 },
 uint8: {
  type: "unsigned int8",
  byteSize: 1
 },
 short: {
  type: "short",
  byteSize: 2
 },
 unsignedShort: {
  type: "unsigned short",
  byteSize: 2
 },
 long: {
  type: "long",
  byteSize: 4
 },
 unsignedLong: {
  type: "unsigned long",
  byteSize: 4
 },
 longLong: {
  type: "long long",
  byteSize: 8
 },
 unsignedLongLong: {
  type: "unsigned long long",
  byteSize: 8
 },
 float: {
  type: "float",
  byteSize: 4
 },
 double: {
  type: "double",
  byteSize: 8
 },
 string: void 0
}, LASLoader.PHB = class {
 constructor() {
  this._headerLength = 375, this._dataTypes = LASLoader.DataTypes, this._inserts = {
   FILE_SIGNATURE: new LASLoader.PHBInsert("File Signature (“LASF”)", this._dataTypes.char, 4, !0, 0),
   FILE_SOURCE_ID: new LASLoader.PHBInsert("File Source ID", this._dataTypes.unsignedShort, 1, !0, 4),
   GLOBAL_ENCODING: new LASLoader.PHBInsert("Global Encoding", this._dataTypes.unsignedShort, 1, !0, 6),
   GUID_DATA_1: new LASLoader.PHBInsert("Project ID - GUID Data 1", this._dataTypes.unsignedLong, 1, !1, 8),
   GUID_DATA_2: new LASLoader.PHBInsert("Project ID - GUID Data 2", this._dataTypes.unsignedShort, 1, !1, 12),
   GUID_DATA_3: new LASLoader.PHBInsert("Project ID - GUID Data 3", this._dataTypes.unsignedShort, 1, !1, 14),
   GUID_DATA_4: new LASLoader.PHBInsert("Project ID - GUID Data 4", this._dataTypes.unsignedChar, 8, !1, 16),
   VERSION_MAJOR: new LASLoader.PHBInsert("Version Major", this._dataTypes.uint8, 1, !0, 24),
   VERSION_MINOR: new LASLoader.PHBInsert("Version Minor", this._dataTypes.uint8, 1, !0, 25),
   SYSTEM_IDENTIFIER: new LASLoader.PHBInsert("System Identifier", this._dataTypes.char, 32, !0, 26),
   GENERATING_SOFTWARE: new LASLoader.PHBInsert("Generating Software ", this._dataTypes.char, 32, !0, 58),
   FILE_CREATION_DAY: new LASLoader.PHBInsert("File Creation Day of Year", this._dataTypes.unsignedShort, 1, !0, 90),
   FILE_CREATION_YEAR: new LASLoader.PHBInsert("File Creation Year", this._dataTypes.unsignedShort, 1, !0, 92),
   HEADER_SIZE: new LASLoader.PHBInsert("Header Size", this._dataTypes.unsignedShort, 1, !0, 94),
   OFFSET_TO_POINT_DATA: new LASLoader.PHBInsert("Offset to Point Data", this._dataTypes.unsignedLong, 1, !0, 96),
   NUMBER_OF_VARIABLE_LENGTH_RECORDS: new LASLoader.PHBInsert("Number of Variable Length Records", this._dataTypes.unsignedLong, 1, !0, 100),
   POINT_DATA_RECORD_FORMAT: new LASLoader.PHBInsert("Point Data Record Format", this._dataTypes.uint8, 1, !0, 104),
   POINT_DATA_RECORD_LENGTH: new LASLoader.PHBInsert("Point Data Record Length", this._dataTypes.unsignedShort, 1, !0, 105),
   LEGACY_NUMBER_OF_POINT_RECORDS: new LASLoader.PHBInsert("Legacy Number of Point Records", this._dataTypes.unsignedLong, 1, !0, 107),
   LEGACY_NUMBER_OF_POINT_BY_RETURN: new LASLoader.PHBInsert("Legacy Number of Point by Return", this._dataTypes.unsignedLong, 20, !0, 111),
   X_SCALE_FACTOR: new LASLoader.PHBInsert("X Scale Factor", this._dataTypes.double, 1, !0, 131),
   Y_SCALE_FACTOR: new LASLoader.PHBInsert("Y Scale Factor", this._dataTypes.double, 1, !0, 139),
   Z_SCALE_FACTOR: new LASLoader.PHBInsert("Z Scale Factor", this._dataTypes.double, 1, !0, 147),
   X_OFFSET: new LASLoader.PHBInsert("X Offset", this._dataTypes.double, 1, !0, 155),
   Y_OFFSET: new LASLoader.PHBInsert("Y Offset", this._dataTypes.double, 1, !0, 163),
   Z_OFFSET: new LASLoader.PHBInsert("Z Offset", this._dataTypes.double, 1, !0, 171),
   MAX_X: new LASLoader.PHBInsert("Max X", this._dataTypes.double, 1, !0, 179),
   MAX_Y: new LASLoader.PHBInsert("Max Y", this._dataTypes.double, 1, !0, 187),
   MAX_Z: new LASLoader.PHBInsert("Max Z", this._dataTypes.double, 1, !0, 195),
   MIN_X: new LASLoader.PHBInsert("Min X", this._dataTypes.double, 1, !0, 203),
   MIN_Y: new LASLoader.PHBInsert("Min Y", this._dataTypes.double, 1, !0, 211),
   MIN_Z: new LASLoader.PHBInsert("Min Z", this._dataTypes.double, 1, !0, 219),
   START_OF_WAVEFORM_DATA_PACKET_RECORD: new LASLoader.PHBInsert("Start of Waveform Data Packet Record", this._dataTypes.unsignedLongLong, 1, !0, 227),
   START_OF_FIRST_EXTENDED_VARIABLE_LENGTH_RECORD: new LASLoader.PHBInsert("Start of First Extended Variable Length Record", this._dataTypes.unsignedLongLong, 1, !0, 235),
   NUMBER_OF_EXTENDED_VARIABLE_LENGTH_RECORDS: new LASLoader.PHBInsert("Number of Extended Variable Length Records", this._dataTypes.unsignedLong, 1, !0, 243),
   NUMBER_OF_POINT_RECORDS: new LASLoader.PHBInsert("Number of Point Records", this._dataTypes.unsignedLongLong, 1, !0, 247),
   NUMBER_OF_POINTS_BY_RETURN: new LASLoader.PHBInsert("Number of Points by Return", this._dataTypes.unsignedLongLong, 15, !0, 255)
  };
 }
 get headerLength() {
  return this._headerLength;
 }
 get inserts() {
  return this._inserts;
 }
}, LASLoader.Insert = class {
 constructor(t, e, i, r, s) {
  this._item = t, this._format = e, this._size = i, this._required = r, this._offset = s, 
  this._data = null;
 }
 set item(t) {
  this._item = t;
 }
 set format(t) {
  this._format = t;
 }
 set size(t) {
  this._size = t;
 }
 set required(t) {
  this._required = t;
 }
 set offset(t) {
  this._offset = t;
 }
 set data(t) {
  this._data = t;
 }
 get item() {
  return this._item;
 }
 get format() {
  return this._format;
 }
 get size() {
  return this._size;
 }
 get required() {
  return this._required;
 }
 get offset() {
  return this._offset;
 }
 get data() {
  return this._data;
 }
 get hasData() {
  return null != this._data;
 }
 get endOffset() {
  return this._offset + this._format.byteSize * this._size;
 }
}, LASLoader.PHBInsert = class extends LASLoader.Insert {
 constructor(t, e, i, r, s) {
  super(t, e, i, r, s);
 }
}, LASLoader.VLR = class {
 constructor() {
  this._headerLength = 54, this._dataTypes = LASLoader.DataTypes, this._inserts = {
   RESERVED: new LASLoader.VLRInsert("Reserved", this._dataTypes.unsignedShort, 2, void 0, 0),
   USER_ID: new LASLoader.VLRInsert("User ID", this._dataTypes.char, 16, !0, 2),
   RECORD_ID: new LASLoader.VLRInsert("Record ID", this._dataTypes.unsignedShort, 2, !0, 18),
   RECORD_LENGTH_AFTER_HEADER: new LASLoader.VLRInsert("Record Length After Header", this._dataTypes.unsignedShort, 2, !0, 20),
   DESCRIPTION: new LASLoader.VLRInsert("Description", this._dataTypes.char, 32, void 0, 22)
  };
 }
 get headerLength() {
  return this._headerLength;
 }
 get inserts() {
  return this._inserts;
 }
}, LASLoader.VLRInsert = class extends LASLoader.Insert {
 constructor(t, e, i, r, s) {
  super(t, e, i, r, s);
 }
}, LASLoader.PDRInsert = class extends LASLoader.Insert {
 constructor(t, e, i, r, s) {
  super(t, e, i, r, s);
 }
}, LASLoader.PDRFormat0 = class {
 constructor() {
  this._minSize = 20, this._dataTypes = LASLoader.DataTypes, this._inserts = {
   X: new LASLoader.PDRInsert("X", this._dataTypes.long, 4, !0, 0),
   Y: new LASLoader.PDRInsert("Y", this._dataTypes.long, 4, !0, 4),
   Z: new LASLoader.PDRInsert("Z", this._dataTypes.long, 4, !0, 8),
   INTENSITY: new LASLoader.PDRInsert("Intensity", this._dataTypes.unsignedShort, 2, !1, 12),
   RETURN_NUMBER: new LASLoader.PDRInsert("Return Number", this._dataTypes.unsignedChar, 1, !0, 14),
   NUMBER_OR_RETURNS: new LASLoader.PDRInsert("Number of Returns (Given Pulse)", this._dataTypes.unsignedChar, 1, !0, 14),
   SCAN_DIRECTION_FLAG: new LASLoader.PDRInsert("Scan Direction Flag", this._dataTypes.unsignedChar, 1, !0, 14),
   EDGE_OF_FLIGHT_LINE: new LASLoader.PDRInsert("Edge of Flight Line", this._dataTypes.unsignedChar, 1, !0, 14),
   CLASSIFICATION: new LASLoader.PDRInsert("Classification", this._dataTypes.unsignedChar, 1, !0, 15),
   SCAN_ANGELE_RANK: new LASLoader.PDRInsert("Scan Angle Rank (-90 to +90) – Left Side", this._dataTypes.char, 1, !0, 16),
   USER_DATA: new LASLoader.PDRInsert("User Data", this._dataTypes.unsignedChar, 1, !1, 17),
   POINT_SOURCE_ID: new LASLoader.PDRInsert("Point Source ID", this._dataTypes.unsignedShort, 2, !0, 18)
  };
 }
 set minSize(t) {
  this._minSize = t;
 }
 get minSize() {
  return this._minSize;
 }
 get inserts() {
  return this._inserts;
 }
}, LASLoader.PDRFormat0.Keys = {
 X: "X",
 Y: "Y",
 Z: "Z",
 INTENSITY: "INTENSITY",
 RETURN_NUMBER: "RETURN_NUMBER",
 NUMBER_OR_RETURNS: "NUMBER_OR_RETURNS",
 SCAN_DIRECTION_FLAG: "SCAN_DIRECTION_FLAG",
 EDGE_OF_FLIGHT_LINE: "EDGE_OF_FLIGHT_LINE",
 CLASSIFICATION: "CLASSIFICATION",
 SCAN_ANGELE_RANK: "SCAN_ANGELE_RANK",
 USER_DATA: "USER_DATA",
 POINT_SOURCE_ID: "POINT_SOURCE_ID"
}, LASLoader.PDRFormat1 = class extends LASLoader.PDRFormat0 {
 constructor() {
  super(), this.minSize = 28, Object.assign(this._inserts, {
   GPS_TIME: new LASLoader.PDRInsert("GPS Time", this._dataTypes.double, 8, !0, 20)
  });
 }
}, LASLoader.PDRFormat1.Keys = Object.assign({}, LASLoader.PDRFormat0.Keys, {
 GPS_TIME: "GPS_TIME"
}), LASLoader.PDRFormat2 = class extends LASLoader.PDRFormat0 {
 constructor() {
  super(), this.minSize = 26, Object.assign(this._inserts, {
   RED: new LASLoader.PDRInsert("Red", this._dataTypes.uint8, 1, !0, 21),
   GREEN: new LASLoader.PDRInsert("Green", this._dataTypes.uint8, 1, !0, 23),
   BLUE: new LASLoader.PDRInsert("Blue", this._dataTypes.uint8, 1, !0, 25),
   NX: new LASLoader.PDRInsert("NX", this._dataTypes.uint8, 1, !0, 20),
   NY: new LASLoader.PDRInsert("NY", this._dataTypes.uint8, 1, !0, 22),
   NZ: new LASLoader.PDRInsert("NZ", this._dataTypes.uint8, 1, !0, 24)
  });
 }
}, LASLoader.PDRFormat2.Keys = Object.assign({}, LASLoader.PDRFormat0.Keys, {
 RED: "RED",
 GREEN: "GREEN",
 BLUE: "BLUE",
 NX: "NX",
 NY: "NY",
 NZ: "NZ"
}), LASLoader.PDRFormat3 = class extends LASLoader.PDRFormat1 {
 constructor() {
  super(), this.minSize = 34, Object.assign(this._inserts, {
   RED: new LASLoader.PDRInsert("Red", this._dataTypes.unsignedShort, 2, !0, 28),
   GREEN: new LASLoader.PDRInsert("Green", this._dataTypes.unsignedShort, 2, !0, 30),
   BLUE: new LASLoader.PDRInsert("Blue", this._dataTypes.unsignedShort, 2, !0, 32)
  });
 }
}, LASLoader.PDRFormat3.Keys = Object.assign({}, LASLoader.PDRFormat1.Keys, {
 RED: "RED",
 GREEN: "GREEN",
 BLUE: "BLUE"
}), LASLoader.PDRFormat4 = class extends LASLoader.PDRFormat1 {
 constructor() {
  super(), this.minSize = 57, Object.assign(this._inserts, {
   WAVE_PACKET_DESCRIPTOR_INDEX: new LASLoader.PDRInsert("Wave Packet Descriptor Index", this._dataTypes.unsignedChar, 1, !0, 28),
   BYTE_OFFSET_TO_WAVEFORM_DATA: new LASLoader.PDRInsert("Byte Offset to Waveform Data", this._dataTypes.unsignedLongLong, 8, !0, 29),
   WAVEFORM_PACKET_SIZE_IN_BYTES: new LASLoader.PDRInsert("Waveform Packet Size in Bytes", this._dataTypes.unsignedLong, 4, !0, 37),
   RETURN_POINT_WAVEFORM_LOCATION: new LASLoader.PDRInsert("Return Point Waveform Location", this._dataTypes.float, 4, !0, 41),
   PARAMETRIC_DX: new LASLoader.PDRInsert("Parametric dx", this._dataTypes.float, 4, !0, 45),
   PARAMETRIC_DY: new LASLoader.PDRInsert("Parametric dy", this._dataTypes.float, 4, !0, 49),
   PARAMETRIC_DZ: new LASLoader.PDRInsert("Parametric dz", this._dataTypes.float, 4, !0, 53)
  });
 }
}, LASLoader.PDRFormat4.Keys = Object.assign({}, LASLoader.PDRFormat1.Keys, {
 WAVE_PACKET_DESCRIPTOR_INDEX: "WAVE_PACKET_DESCRIPTOR_INDEX",
 BYTE_OFFSET_TO_WAVEFORM_DATA: "BYTE_OFFSET_TO_WAVEFORM_DATA",
 WAVEFORM_PACKET_SIZE_IN_BYTES: "WAVEFORM_PACKET_SIZE_IN_BYTES",
 RETURN_POINT_WAVEFORM_LOCATION: "RETURN_POINT_WAVEFORM_LOCATION",
 PARAMETRIC_DX: "PARAMETRIC_DX",
 PARAMETRIC_DY: "PARAMETRIC_DY",
 PARAMETRIC_DZ: "PARAMETRIC_DZ"
}), LASLoader.PDRFormat5 = class extends LASLoader.PDRFormat3 {
 constructor() {
  super(), this.minSize = 63, Object.assign(this._inserts, {
   WAVE_PACKET_DESCRIPTOR_INDEX: new LASLoader.PDRInsert("Wave Packet Descriptor Index", this._dataTypes.unsignedChar, 1, !0, 34),
   BYTE_OFFSET_TO_WAVEFORM_DATA: new LASLoader.PDRInsert("Byte Offset to Waveform Data", this._dataTypes.unsignedLongLong, 8, !0, 35),
   WAVEFORM_PACKET_SIZE_IN_BYTES: new LASLoader.PDRInsert("Waveform Packet Size in Bytes", this._dataTypes.unsignedLong, 4, !0, 43),
   RETURN_POINT_WAVEFORM_LOCATION: new LASLoader.PDRInsert("Return Point Waveform Location", this._dataTypes.float, 4, !0, 47),
   PARAMETRIC_DX: new LASLoader.PDRInsert("Parametric dx", this._dataTypes.float, 4, !0, 51),
   PARAMETRIC_DY: new LASLoader.PDRInsert("Parametric dy", this._dataTypes.float, 4, !0, 55),
   PARAMETRIC_DZ: new LASLoader.PDRInsert("Parametric dz", this._dataTypes.float, 4, !0, 59)
  });
 }
}, LASLoader.PDRFormat5.Keys = Object.assign({}, LASLoader.PDRFormat3.Keys, {
 WAVE_PACKET_DESCRIPTOR_INDEX: "WAVE_PACKET_DESCRIPTOR_INDEX",
 BYTE_OFFSET_TO_WAVEFORM_DATA: "BYTE_OFFSET_TO_WAVEFORM_DATA",
 WAVEFORM_PACKET_SIZE_IN_BYTES: "WAVEFORM_PACKET_SIZE_IN_BYTES",
 RETURN_POINT_WAVEFORM_LOCATION: "RETURN_POINT_WAVEFORM_LOCATION",
 PARAMETRIC_DX: "PARAMETRIC_DX",
 PARAMETRIC_DY: "PARAMETRIC_DY",
 PARAMETRIC_DZ: "PARAMETRIC_DZ"
}), LASLoader.PDRFormat6 = class extends LASLoader.PDRFormat0 {
 constructor() {
  super(), this.minSize = 30, this._inserts = {
   X: new LASLoader.PDRInsert("X", this._dataTypes.long, 4, !0, 0),
   Y: new LASLoader.PDRInsert("Y", this._dataTypes.long, 4, !0, 4),
   Z: new LASLoader.PDRInsert("Z", this._dataTypes.long, 4, !0, 8),
   INTENSITY: new LASLoader.PDRInsert("Intensity", this._dataTypes.unsignedShort, 2, !1, 12),
   RETURN_NUMBER: new LASLoader.PDRInsert("Return Number", this._dataTypes.unsignedChar, 1, !0, 14),
   NUMBER_OR_RETURNS: new LASLoader.PDRInsert("Number of Returns (Given Pulse)", this._dataTypes.unsignedChar, 1, !0, 14),
   CLASSIFICATION_FLAGS: new LASLoader.PDRInsert("Classification Flags", this._dataTypes.unsignedChar, 1, !1, 15),
   SCANNER_CHANNEL: new LASLoader.PDRInsert("Scanner Channel", this._dataTypes.unsignedChar, 1, !0, 15),
   SCAN_DIRECTION_FLAG: new LASLoader.PDRInsert("Scan Direction Flag", this._dataTypes.unsignedChar, 1, !0, 15),
   EDGE_OF_FLIGHT_LINE: new LASLoader.PDRInsert("Edge of Flight Line", this._dataTypes.unsignedChar, 1, !0, 15),
   CLASSIFICATION: new LASLoader.PDRInsert("Classification", this._dataTypes.unsignedChar, 1, !0, 16),
   USER_DATA: new LASLoader.PDRInsert("User Data", this._dataTypes.unsignedChar, 1, !1, 17),
   SCAN_ANGELE: new LASLoader.PDRInsert("Scan Angle", this._dataTypes.short, 2, !0, 18),
   POINT_SOURCE_ID: new LASLoader.PDRInsert("Point Source ID", this._dataTypes.unsignedShort, 2, !0, 20),
   GPS_TIME: new LASLoader.PDRInsert("GPS Time", this._dataTypes.double, 8, !0, 22)
  };
 }
}, LASLoader.PDRFormat6.Keys = Object.assign({}, LASLoader.PDRFormat0.Keys, {
 X: "X",
 Y: "Y",
 Z: "Z",
 INTENSITY: "INTENSITY",
 RETURN_NUMBER: "RETURN_NUMBER",
 NUMBER_OR_RETURNS: "NUMBER_OR_RETURNS",
 CLASSIFICATION_FLAGS: "CLASSIFICATION_FLAGS",
 SCANNER_CHANNEL: "SCANNER_CHANNEL",
 SCAN_DIRECTION_FLAG: "SCAN_DIRECTION_FLAG",
 EDGE_OF_FLIGHT_LINE: "EDGE_OF_FLIGHT_LINE",
 CLASSIFICATION: "CLASSIFICATION",
 SCAN_ANGELE_RANK: void 0,
 USER_DATA: "USER_DATA",
 SCAN_ANGELE: "SCAN_ANGELE",
 POINT_SOURCE_ID: "POINT_SOURCE_ID",
 GPS_TIME: "GPS_TIME"
}), LASLoader.PDRFormat7 = class extends LASLoader.PDRFormat6 {
 constructor() {
  super(), this.minSize = 36, Object.assign(this._inserts, {
   RED: new LASLoader.PDRInsert("Red", this._dataTypes.unsignedShort, 2, !0, 30),
   GREEN: new LASLoader.PDRInsert("Green", this._dataTypes.unsignedShort, 2, !0, 32),
   BLUE: new LASLoader.PDRInsert("Blue", this._dataTypes.unsignedShort, 2, !0, 34)
  });
 }
}, LASLoader.PDRFormat7.Keys = Object.assign({}, LASLoader.PDRFormat6.Keys, {
 RED: "RED",
 GREEN: "GREEN",
 BLUE: "BLUE"
}), LASLoader.PDRFormat8 = class extends LASLoader.PDRFormat7 {
 constructor() {
  super(), this.minSize = 38, Object.assign(this._inserts, {
   NIR: new LASLoader.PDRInsert("NIR", this._dataTypes.unsignedShort, 2, !0, 36)
  });
 }
}, LASLoader.PDRFormat8.Keys = Object.assign({}, LASLoader.PDRFormat7.Keys, {
 NIR: "NIR"
}), LASLoader.PDRFormat9 = class extends LASLoader.PDRFormat6 {
 constructor() {
  super(), this.minSize = 59, Object.assign(this._inserts, {
   WAVE_PACKET_DESCRIPTOR_INDEX: new LASLoader.PDRInsert("Wave Packet Descriptor Index", this._dataTypes.unsignedChar, 1, !0, 30),
   BYTE_OFFSET_TO_WAVEFORM_DATA: new LASLoader.PDRInsert("Byte Offset to Waveform Data", this._dataTypes.unsignedLongLong, 8, !0, 31),
   WAVEFORM_PACKET_SIZE_IN_BYTES: new LASLoader.PDRInsert("Waveform Packet Size in Bytes", this._dataTypes.unsignedLong, 4, !0, 39),
   RETURN_POINT_WAVEFORM_LOCATION: new LASLoader.PDRInsert("Return Point Waveform Location", this._dataTypes.float, 4, !0, 43),
   PARAMETRIC_DX: new LASLoader.PDRInsert("Parametric dx", this._dataTypes.float, 4, !0, 47),
   PARAMETRIC_DY: new LASLoader.PDRInsert("Parametric dy", this._dataTypes.float, 4, !0, 51),
   PARAMETRIC_DZ: new LASLoader.PDRInsert("Parametric dz", this._dataTypes.float, 4, !0, 55)
  });
 }
}, LASLoader.PDRFormat9.Keys = Object.assign({}, LASLoader.PDRFormat6.Keys, {
 WAVE_PACKET_DESCRIPTOR_INDEX: "WAVE_PACKET_DESCRIPTOR_INDEX",
 BYTE_OFFSET_TO_WAVEFORM_DATA: "BYTE_OFFSET_TO_WAVEFORM_DATA",
 WAVEFORM_PACKET_SIZE_IN_BYTES: "WAVEFORM_PACKET_SIZE_IN_BYTES",
 RETURN_POINT_WAVEFORM_LOCATION: "RETURN_POINT_WAVEFORM_LOCATION",
 PARAMETRIC_DX: "PARAMETRIC_DX",
 PARAMETRIC_DY: "PARAMETRIC_DY",
 PARAMETRIC_DZ: "PARAMETRIC_DZ"
}), LASLoader.PDRFormat10 = class extends LASLoader.PDRFormat8 {
 constructor() {
  super(), this.minSize = 67, Object.assign(this._inserts, {
   WAVE_PACKET_DESCRIPTOR_INDEX: new LASLoader.PDRInsert("Wave Packet Descriptor Index", this._dataTypes.unsignedChar, 1, !0, 38),
   BYTE_OFFSET_TO_WAVEFORM_DATA: new LASLoader.PDRInsert("Byte Offset to Waveform Data", this._dataTypes.unsignedLongLong, 8, !0, 39),
   WAVEFORM_PACKET_SIZE_IN_BYTES: new LASLoader.PDRInsert("Waveform Packet Size in Bytes", this._dataTypes.unsignedLong, 4, !0, 47),
   RETURN_POINT_WAVEFORM_LOCATION: new LASLoader.PDRInsert("Return Point Waveform Location", this._dataTypes.float, 4, !0, 51),
   PARAMETRIC_DX: new LASLoader.PDRInsert("Parametric dx", this._dataTypes.float, 4, !0, 55),
   PARAMETRIC_DY: new LASLoader.PDRInsert("Parametric dy", this._dataTypes.float, 4, !0, 59),
   PARAMETRIC_DZ: new LASLoader.PDRInsert("Parametric dz", this._dataTypes.float, 4, !0, 63)
  });
 }
}, LASLoader.PDRFormat10.Keys = Object.assign({}, LASLoader.PDRFormat8.Keys, {
 WAVE_PACKET_DESCRIPTOR_INDEX: "WAVE_PACKET_DESCRIPTOR_INDEX",
 BYTE_OFFSET_TO_WAVEFORM_DATA: "BYTE_OFFSET_TO_WAVEFORM_DATA",
 WAVEFORM_PACKET_SIZE_IN_BYTES: "WAVEFORM_PACKET_SIZE_IN_BYTES",
 RETURN_POINT_WAVEFORM_LOCATION: "RETURN_POINT_WAVEFORM_LOCATION",
 PARAMETRIC_DX: "PARAMETRIC_DX",
 PARAMETRIC_DY: "PARAMETRIC_DY",
 PARAMETRIC_DZ: "PARAMETRIC_DZ"
});

class Canvas {
 constructor(t) {
  this._canvasDOM = this.generateCanvasDOM(), this._parentDOM = void 0 !== t ? t.appendChild(this._canvasDOM).parentElement : null, 
  this._uuid = _Math.generateUUID(), this._pixelRatio = window.devicePixelRatio || 1, 
  this.updateSize();
 }
 get pixelRatio() {
  return this._pixelRatio;
 }
 set pixelRatio(t) {
  this._pixelRatio = t;
 }
 set canvasDOM(t) {
  this._canvasDOM = t;
 }
 set parentDOM(t) {
  this._parentDOM = t.appendChild(this._canvasDOM).parentElement, canvasDOM.width = t.clientWidth, 
  canvasDOM.height = t.clientHeight;
 }
 set uuid(t) {
  this._uuid = t;
 }
 set width(t) {
  this._canvasDOM.width = t;
 }
 set height(t) {
  this._canvasDOM.height = t;
 }
 get canvasDOM() {
  return this._canvasDOM;
 }
 get parentDOM() {
  return this._parentDOM;
 }
 get uuid() {
  return this._uuid;
 }
 get width() {
  return this._canvasDOM.width;
 }
 get height() {
  return this._canvasDOM.height;
 }
 generateCanvasDOM(t = "rc-canvas") {
  var e = document.createElement("canvas");
  return e.id = t, e.style.width = "100%", e.style.height = "100%", e.style.padding = "0", 
  e.style.margin = "0", e;
 }
 updateSize() {
  this._canvasDOM.width = Math.floor(this._canvasDOM.clientWidth * this.pixelRatio), 
  this._canvasDOM.height = Math.floor(this._canvasDOM.clientHeight * this.pixelRatio);
 }
}

class Cube extends Mesh {
 constructor(e, t) {
  var i = new Geometry(), r = new MeshBasicMaterial();
  r.color = t, i.vertices = Float32Attribute([ -1, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1 ], 3);
  for (let t = 0; t < i.vertices.array.length; t++) i.vertices.array[t] *= e;
  i.indices = Uint32Attribute([ 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23 ], 1), 
  i.computeVertexNormals(), i.uv = Float32Attribute([ 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1 ], 2), 
  super(i, r), this.type = "Cube";
 }
}

class Group extends Object3D {
 constructor() {
  super(Object3D), this.type = "Group", this._frustumCulled = !1;
 }
 static fromJson(t) {
  var e = new Group();
  return super.fromJson(t, e);
 }
 fillRenderArray() {}
 project() {}
 getRequiredPrograms(t) {
  return [];
 }
 update(t, e) {}
}

class Camera extends Object3D {
 constructor() {
  super(Object3D), this.type = "Camera", this._matrixWorldInverse = new Matrix4(), 
  this._projectionMatrix = new Matrix4(), this.projectionMatrixInverse = new Matrix4(), 
  this._up = new Vector3(0, 1, 0), this._frustum = new Group(), this.add(this._frustum), 
  this._frustum.visible = !1;
 }
 get matrixWorldInverse() {
  return this._matrixWorldInverse;
 }
 set matrixWorldInverse(t) {
  this._matrixWorldInverse = t;
 }
 get projectionMatrix() {
  return this._projectionMatrix;
 }
 set projectionMatrix(t) {
  this._projectionMatrix = t;
 }
 get projectionMatrixInverse() {
  return this._projectionMatrixInverse.getInverse(this._projectionMatrix), this._projectionMatrixInverse;
 }
 set projectionMatrixInverse(t) {
  this._projectionMatrixInverse = t;
 }
 get up() {
  return this._up;
 }
 get frustumVisible() {
  return this._frustum.visible;
 }
 set frustumVisible(t) {
  this._frustum.visible = t;
 }
 fillRenderArray(t) {}
 project() {}
 getRequiredPrograms(t) {
  return [];
 }
 update(t) {}
 updateFrustum() {
  this._frustum.clear();
  var e = new Matrix4().getInverse(this._projectionMatrix), i = [], r = new Array(new Vector4(-1, -1, 1, 1), new Vector4(1, -1, 1, 1), new Vector4(1, 1, 1, 1), new Vector4(-1, 1, 1, 1), new Vector4(-1, -1, -1, 1), new Vector4(1, -1, -1, 1), new Vector4(1, 1, -1, 1), new Vector4(-1, 1, -1, 1));
  for (let t = 0; t < r.length; t++) r[t].applyMatrix4(e), r[t].multiplyScalar(1 / r[t].w), 
  i.push(r[t].x, r[t].y, r[t].z);
  var t = new Cube(1, new Color().setColorName("grey")), t = (t.frustumCulled = !1, 
  t.geometry.vertices = new Float32Attribute(i, 3), t.geometry.indices = new Uint32Attribute([ 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 4, 0, 3, 4, 3, 7, 1, 5, 6, 1, 6, 2, 3, 2, 6, 3, 6, 7, 4, 5, 1, 4, 1, 0 ], 1), 
  t.material.depthTest = !1, t.material.depthWrite = !1, t.material.side = FRONT_AND_BACK_SIDE, 
  t.material.transparent = !0, t.material.opacity = .25, this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[0].x, r[0].y, r[0].z, r[1].x, r[1].y, r[1].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[1].x, r[1].y, r[1].z, r[2].x, r[2].y, r[2].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[2].x, r[2].y, r[2].z, r[3].x, r[3].y, r[3].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[3].x, r[3].y, r[3].z, r[0].x, r[0].y, r[0].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[4].x, r[4].y, r[4].z, r[5].x, r[5].y, r[5].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[5].x, r[5].y, r[5].z, r[6].x, r[6].y, r[6].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[6].x, r[6].y, r[6].z, r[7].x, r[7].y, r[7].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[7].x, r[7].y, r[7].z, r[4].x, r[4].y, r[4].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[0].x, r[0].y, r[0].z, r[4].x, r[4].y, r[4].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[1].x, r[1].y, r[1].z, r[5].x, r[5].y, r[5].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[2].x, r[2].y, r[2].z, r[6].x, r[6].y, r[6].z ], 3), 
  t.computeVertexNormals(), new Line(t)), t = (this._frustum.add(t), new Geometry()), t = (t.vertices = new Float32Attribute([ r[3].x, r[3].y, r[3].z, r[7].x, r[7].y, r[7].z ], 3), 
  t.computeVertexNormals(), new Line(t));
  this._frustum.add(t);
 }
 prePickStoreTBLR() {
  this._top_store = this._top, this._bottom_store = this._bottom, this._left_store = this._left, 
  this._right_store = this._right;
 }
 postPickRestoreTBLR() {
  this._top = this._top_store, this._bottom = this._bottom_store, this._left = this._left_store, 
  this._right = this._right_store, this.updateProjectionMatrix();
 }
}

class PerspectiveCamera extends Camera {
 constructor(t, e, i, r, s = void 0, a = void 0, n = void 0, o = void 0) {
  super(Camera), this.type = "PerspectiveCamera", this._fov = t || 50, this._aspect = e || 1, 
  this._near = i || .1, this._far = r || 1e3, this._top = n || this._near * Math.tan(Math.PI / 180 * .5 * this._fov), 
  this._bottom = o || -this._top, this._left = s || this._aspect * (2 * this._top) * -.5, 
  this._right = a || -this._left, this.updateProjectionMatrix();
 }
 updateProjectionMatrix() {
  this.projectionMatrix.makePerspective(this._left, this._right, this._top, this._bottom, this._near, this._far), 
  this.frustumVisible && this.updateFrustum();
 }
 _updateTBLR() {
  this._top = this._near * Math.tan(Math.PI / 180 * .5 * this._fov), this._bottom = -this._top, 
  this._updateLR();
 }
 _updateLR() {
  this._left = this._aspect * (2 * this._top) * -.5, this._right = -this._left;
 }
 get fov() {
  return this._fov;
 }
 get aspect() {
  return this._aspect;
 }
 get near() {
  return this._near;
 }
 get far() {
  return this._far;
 }
 get left() {
  return this._left;
 }
 get right() {
  return this._right;
 }
 get top() {
  return this._top;
 }
 get bottom() {
  return this._bottom;
 }
 set fov(t) {
  t !== this._fov && (this._fov = t, this._updateTBLR(), this.updateProjectionMatrix(), 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    fov: this._fov
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set aspect(t) {
  t !== this._aspect && (this._aspect = t, this._updateLR(), this.updateProjectionMatrix());
 }
 set near(t) {
  t !== this._near && (this._near = t, this._updateTBLR(), this.updateProjectionMatrix(), 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    near: this._near
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set far(t) {
  t !== this._far && (this._far = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    far: this._far
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set left(t) {
  t !== this._left && (this._left = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    left: this._left
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set right(t) {
  t !== this._right && (this._right = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    right: this._right
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set top(t) {
  t !== this._top && (this._top = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    top: this._top
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set bottom(t) {
  t !== this._bottom && (this._bottom = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    bottom: this._bottom
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 toJson() {
  var t = super.toJson();
  return t.fov = this._fov, t.near = this._near, t.far = this._far, t;
 }
 static fromJson(t, e) {
  e = new PerspectiveCamera(t.fov, e, t.near, t.far);
  return super.fromJson(t, e);
 }
 update(t) {
  super.update(t);
  var e, i = !1;
  for (e in t) switch (e) {
  case "fov":
   this._fov = t.fov, delete t.fov, i = !0;
   break;

  case "near":
   this._near = t.near, delete t.near, i = !0;
   break;

  case "far":
   this._far = t.far, delete t.far, i = !0;
   break;

  case "left":
   this._left = t.left, delete t.left, i = !0;
   break;

  case "right":
   this._right = t.right, delete t.right, i = !0;
   break;

  case "top":
   this._top = t.top, delete t.top, i = !0;
   break;

  case "bottom":
   this._bottom = t.bottom, delete t.bottom, i = !0;
  }
  i && this.updateProjectionMatrix();
 }
 narrowProjectionForPicking(t, e, i, r, s, a) {
  this._top = (a + r / 2) / e * (this._top_store - this._bottom_store) + this._bottom_store, 
  this._bottom = (a - r / 2) / e * (this._top_store - this._bottom_store) + this._bottom_store, 
  this._left = (s - i / 2) / t * (this._right_store - this._left_store) + this._left_store, 
  this._right = (s + i / 2) / t * (this._right_store - this._left_store) + this._left_store, 
  this.updateProjectionMatrix();
 }
}

class OrthographicCamera extends Camera {
 constructor(t, e, i, r, s, a) {
  super(Camera), this.type = "OrthographicCamera", this._left = t, this._right = e, 
  this._top = i, this._bottom = r, this._near = void 0 !== s ? s : .1, this._far = void 0 !== a ? a : 2e3, 
  this._aspect = 1, this._zoom = 1, this.updateProjectionMatrix();
 }
 get left() {
  return this._left;
 }
 get right() {
  return this._right;
 }
 get top() {
  return this._top;
 }
 get bottom() {
  return this._bottom;
 }
 set left(t) {
  t !== this._left && (this._left = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    left: this._left
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set right(t) {
  t !== this._right && (this._right = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    right: this._right
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set top(t) {
  t !== this._top && (this._top = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    top: this._top
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set bottom(t) {
  t !== this._bottom && (this._bottom = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    bottom: this._bottom
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get near() {
  return this._near;
 }
 set near(t) {
  t !== this._near && (this._near = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    near: this._near
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get far() {
  return this._far;
 }
 set far(t) {
  t !== this._far && (this._far = t, this.updateProjectionMatrix(), this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    far: this._far
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set aspect(t) {
  t !== this._aspect && (this._aspect = t, this._updateLR(), this.updateProjectionMatrix());
 }
 get aspect() {
  return this._aspect;
 }
 set zoom(t) {
  t !== this._zoom && (this._zoom = t, this.updateProjectionMatrix());
 }
 get zoom() {
  return this._zoom;
 }
 updateProjectionMatrix() {
  var t = (this._right - this._left) / (2 * this._zoom), e = (this._top - this._bottom) / (2 * this._zoom), i = (this._right + this._left) / 2, r = (this._top + this._bottom) / 2;
  this.projectionMatrix.makeOrthographic(i - t, i + t, r + e, r - e, this._near, this._far), 
  this.frustumVisible && this.updateFrustum();
 }
 _updateLR() {
  this._left = -this._top * this._aspect, this._right = -this._left;
 }
 toJson() {
  var t = super.toJson();
  return t.left = this._left, t.right = this._right, t.top = this._top, t.bottom = this._bottom, 
  t.near = this._near, t.far = this._far, t;
 }
 static fromJson(t) {
  var e = new OrthographicCamera(t.left, t.right, t.top, t.bottom, t.near, t.far);
  return super.fromJson(t, e);
 }
 update(t) {
  super.update(t);
  var e, i = !1;
  for (e in t) switch (e) {
  case "fov":
   this._fov = t.fov, delete t.fov, i = !0;
   break;

  case "near":
   this._near = t.near, delete t.near, i = !0;
   break;

  case "far":
   this._far = t.far, delete t.far, i = !0;
  }
  i && this.updateProjectionMatrix();
 }
 narrowProjectionForPicking(t, e, i, r, s, a) {
  var n = (this._right_store - this._left_store) / (2 * this._zoom), o = (this._top_store - this._bottom_store) / (2 * this._zoom), h = (this._right_store + this._left_store) / 2, u = (this._top_store + this._bottom_store) / 2, l = h - n, h = h + n, n = u + o, u = u - o;
  this.projectionMatrix.makeOrthographic((s - i / 2) / t * (h - l) + l, (s + i / 2) / t * (h - l) + l, (a + r / 2) / e * (n - u) + u, (a - r / 2) / e * (n - u) + u, this._near, this._far), 
  this.frustumVisible && this.updateFrustum();
 }
}

class Raycaster {
 constructor(t, e, i, r) {
  this.ray = new Ray(t, e), this.near = i || 0, this.far = r || 1 / 0;
 }
 setFromCamera(t, e) {
  e instanceof PerspectiveCamera ? (this.ray.origin.setFromMatrixPosition(e.matrixWorld), 
  this.ray.direction.set(t.x, t.y, .5).unproject(e).sub(this.ray.origin).normalize()) : e instanceof OrthographicCamera && (this.ray.origin.set(t.x, t.y, (e.near + e.far) / (e.near - e.far)).unproject(e), 
  this.ray.direction.set(0, 0, -1).transformDirection(e.matrixWorld));
 }
 static _intersectObject(t, e, i, r) {
  if (!1 !== t.visible && (t.raycast(e, i), !0 === r)) for (var s = t.children, a = 0; a < s.length; a++) Raycaster._intersectObject(s[a], e, i, !0);
 }
 intersectObject(t, e) {
  var i = [];
  return Raycaster._intersectObject(t, this, i, e), i.sort(function(t, e) {
   return t.distance - e.distance;
  }), i;
 }
 intersectObjects(t, e) {
  var i = [];
  if (!1 === Array.isArray(t)) console.warn("Raycaster: warning the given objects is not an array."); else {
   for (var r = 0; r < t.length; r++) Raycaster._intersectObject(t[r], this, i, e);
   i.sort(function(t, e) {
    return t.distance - e.distance;
   });
  }
  return i;
 }
}

class Scene extends Object3D {
 constructor() {
  super(Object3D), this.type = "Scene", this._autoUpdate = !0, this.frustumCulled = !1;
 }
 get autoUpdate() {
  return this._autoUpdate;
 }
 set autoUpdate(t) {
  t !== this._autoUpdate && (this._autoUpdate = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    autoUpdate: this._autoUpdate
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 toJson() {
  var t = super.toJson();
  return t.autoUpdate = this._autoUpdate, t;
 }
 static fromJson(t) {
  var e = new Scene();
  return (e = super.fromJson(t, e))._autoUpdate = t.autoUpdate, e;
 }
 update(t) {
  for (var e in super.update(t), t) "autoUpdate" === e && (this._autoUpdate = t.autoUpdate);
 }
 fillRenderArray() {}
 project() {}
 getRequiredPrograms(t) {
  return [];
 }
 update(t, e) {}
}

class EventDispatcher {
 constructor() {}
 addEventListener(t, e) {
  void 0 === this._listeners && (this._listeners = {});
  var i = this._listeners;
  void 0 === i[t] && (i[t] = []), -1 === i[t].indexOf(e) && i[t].push(e);
 }
 hasEventListener(t, e) {
  var i;
  return void 0 !== this._listeners && void 0 !== (i = this._listeners)[t] && -1 !== i[t].indexOf(e);
 }
 removeEventListener(t, e) {
  var i;
  void 0 !== this._listeners && void 0 !== (t = this._listeners[t]) && -1 !== (i = t.indexOf(e)) && t.splice(i, 1);
 }
 dispatchEvent(i) {
  if (void 0 !== this._listeners) {
   var t = this._listeners[i.type];
   if (void 0 !== t) {
    i.target = this;
    var r = t.slice(0);
    for (let t = 0, e = r.length; t < e; t++) r[t].call(this, i);
   }
  }
 }
}

new Spherical(), new Vector3(), new Vector3(), new Vector3(), new Vector3(), new Vector3(), 
new Vector3(), new Vector3(), new Vector3(), new Vector3(), new Vector3(-1, -1, -1), 
new Vector3(1, 1, 1);

class Light extends Object3D {
 constructor(t, e, i = {}) {
  super(Object3D), this.type = "Light", this._color = new Color(t), this._intensity = void 0 !== e ? e : 1, 
  this._frustumCulled = !1, this._castShadows = void 0 !== i.castShadows && i.castShadows, 
  this._hardShadows = void 0 === i.hardShadows || i.hardShadows, this._minBias = i.minBias || .005, 
  this._maxBias = i.maxBias || .05, this._shadowmap = null, this._cameraGroup = new Group(), 
  this.add(this._cameraGroup), this.frustumVisible = !1;
 }
 get color() {
  return this._color;
 }
 get intensity() {
  return this._intensity;
 }
 set color(t) {
  this._color = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    color: this._color.getHex()
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set intensity(t) {
  this._intensity = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    intensity: this._intensity
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get castShadows() {
  return this._castShadows;
 }
 set castShadows(t) {
  this._castShadows = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    castShadows: this._castShadows
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get hardShadows() {
  return this._hardShadows;
 }
 set hardShadows(t) {
  this._hardShadows = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    hardShadows: this._hardShadows
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get minBias() {
  return this._minBias;
 }
 set minBias(t) {
  this._minBias = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    minBias: this._minBias
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get maxBias() {
  return this._maxBias;
 }
 set maxBias(t) {
  this._maxBias = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    maxBias: this._maxBias
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get shadowmap() {
  return this._shadowmap;
 }
 set shadowmap(t) {
  this._shadowmap = t;
 }
 get cameraGroup() {
  return this._cameraGroup;
 }
 set cameraGroup(t) {
  this._cameraGroup = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    cameraGroup: this._cameraGroup
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get frustumVisible() {
  return this._cameraGroup.visible;
 }
 set frustumVisible(e) {
  this._cameraGroup.visible = e;
  for (let t = 0; t < this._cameraGroup.children.length; t++) this._cameraGroup.children[t].frustumVisible = e;
 }
 toJson() {
  var t = super.toJson();
  return t.color = this._color.getHex(), t.intensity = this.intensity, t;
 }
 static fromJson(t, e) {
  return e = e || new Light(t.color, t.intensity), e = super.fromJson(t, e);
 }
 update(t) {
  for (var e in super.update(t), t) switch (e) {
  case "color":
   this._color.setHex(t.color), delete t.color;
   break;

  case "intensity":
   this._intensity = t.intensity, delete t.intensity;
  }
 }
 fillRenderArray(t) {
  t.lights.addlast(this);
 }
 project() {}
 getRequiredPrograms(t) {
  return [];
 }
 update(t) {}
}

class AmbientLight extends Light {
 constructor(t, e) {
  super(t, e), this.type = "AmbientLight";
 }
 static fromJson(t) {
  var e = new AmbientLight(t.color, t.intensity);
  return super.fromJson(t, e);
 }
}

class DirectionalLight extends Light {
 constructor(t, e, i = {}) {
  super(t, e, i), this.type = "DirectionalLight", this._position.set(0, 1, 0), this.updateMatrix(), 
  this._direction = i.direction || new Vector3(0, 0, -1);
  t = new OrthographicCamera(-64, 64, 64, -64, 0, 128);
  this.cameraGroup.add(t), this.shadowmap = new Texture();
 }
 get direction() {
  return this._direction;
 }
 set direction(t) {
  this._direction = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    direction: this._direction
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get shadowNear() {
  return this.cameraGroup.children[0].near;
 }
 set shadowNear(t) {
  this.cameraGroup.children[0].near = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    shadowNear: this.cameraGroup.children[0].near
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get shadowFar() {
  return this.cameraGroup.children[0].far;
 }
 set shadowFar(t) {
  this.cameraGroup.children[0].far = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    shadowFar: this.cameraGroup.children[0].far
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 static fromJson(t) {
  var e = new directionalLight(t.color, t.intensity);
  return super.fromJson(t, e);
 }
}

class PointLight extends Light {
 constructor(t, e, i, r, s = {}) {
  super(t, e, s), this.type = "PointLight", this._distance = void 0 !== i ? i : 0, 
  this._decay = void 0 !== r ? r : 1, this._constant = void 0 !== s.constant ? s.constant : 1, 
  this._linear = void 0 !== s.linear ? s.linear : .01, this._quadratic = void 0 !== s.quadratic ? s.quadratic : 1e-4;
  var t = new PerspectiveCamera(90, 1, 8, 128), e = new PerspectiveCamera(90, 1, 8, 128), i = new PerspectiveCamera(90, 1, 8, 128), r = new PerspectiveCamera(90, 1, 8, 128), a = new PerspectiveCamera(90, 1, 8, 128), n = new PerspectiveCamera(90, 1, 8, 128);
  t.lookAt(new Vector3(1, 0, 0), new Vector3(0, -1, 0)), e.lookAt(new Vector3(-1, 0, 0), new Vector3(0, -1, 0)), 
  i.lookAt(new Vector3(0, 1, 0), new Vector3(0, 0, 1)), r.lookAt(new Vector3(0, -1, 0), new Vector3(0, 0, -1)), 
  a.lookAt(new Vector3(0, 0, 1), new Vector3(0, -1, 0)), n.lookAt(new Vector3(0, 0, -1), new Vector3(0, -1, 0)), 
  this.cameraGroup.add(t), this.cameraGroup.add(e), this.cameraGroup.add(i), this.cameraGroup.add(r), 
  this.cameraGroup.add(a), this.cameraGroup.add(n), this.shadowmap = new CubeTexture({
   size: s.smap_size || 256
  });
 }
 set distance(t) {
  this._distance = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    distance: this._distance
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 set decay(t) {
  this._decay = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    decay: this._decay
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get distance() {
  return this._distance;
 }
 get decay() {
  return this._decay;
 }
 get shadowNear() {
  return this.cameraGroup.children[5].near;
 }
 set shadowNear(t) {
  this.cameraGroup.children[0].near = t, this.cameraGroup.children[1].near = t, 
  this.cameraGroup.children[2].near = t, this.cameraGroup.children[3].near = t, 
  this.cameraGroup.children[4].near = t, this.cameraGroup.children[5].near = t, 
  this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    shadowNear: this.cameraGroup.children[5].near
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get shadowFar() {
  return this.cameraGroup.children[5].far;
 }
 set shadowFar(t) {
  this.cameraGroup.children[0].far = t, this.cameraGroup.children[1].far = t, this.cameraGroup.children[2].far = t, 
  this.cameraGroup.children[3].far = t, this.cameraGroup.children[4].far = t, this.cameraGroup.children[5].far = t, 
  this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    shadowFar: this.cameraGroup.children[5].far
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get constant() {
  return this._constant;
 }
 set constant(t) {
  this._constant = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    constant: this._constant
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get linear() {
  return this._linear;
 }
 set linear(t) {
  this._linear = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    linear: this._linear
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get quadratic() {
  return this._quadratic;
 }
 set quadratic(t) {
  this._quadratic = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    quadratic: this._quadratic
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 toJson() {
  var t = super.toJson();
  return t.distance = this._distance, t.intensity = this._decay, t;
 }
 static fromJson(t) {
  var e = new PointLight(t.color, t.intensity, t.distance, t.decay);
  return super.fromJson(t, e);
 }
 update(t) {
  for (var e in super.update(t), t) switch (e) {
  case "distance":
   this._distance.set(t.distance), delete t.distance;
   break;

  case "decay":
   this._decay = t.decay, delete t.decay;
  }
 }
}

class SpotLight extends Light {
 constructor(t = {}) {
  super(t.color, t.intensity, t), this.type = "SpotLight", this._distance = t.distance || 0, 
  this._decay = t.decay || 1, this._constant = void 0 !== t.constant ? t.constant : 1, 
  this._linear = void 0 !== t.linear ? t.linear : .01, this._quadratic = void 0 !== t.quadratic ? t.quadratic : 1e-4, 
  this._cutoff = t.cutoff || Math.PI / 4, this._outerCutoff = t.outerCutoff || 1.1 * this.cutoff, 
  this._direction = t.direction || new Vector3(0, 0, -1), this._up = t.up || new Vector3(0, 1, 0);
  t = new PerspectiveCamera(90, 1, 8, 128);
  this.cameraGroup.add(t), this.shadowmap = new Texture();
 }
 get distance() {
  return this._distance;
 }
 set distance(t) {
  this._distance = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    distance: this._distance
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get decay() {
  return this._decay;
 }
 set decay(t) {
  this._decay = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    decay: this._decay
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get constant() {
  return this._constant;
 }
 set constant(t) {
  this._constant = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    constant: this._constant
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get linear() {
  return this._linear;
 }
 set linear(t) {
  this._linear = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    linear: this._linear
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get quadratic() {
  return this._quadratic;
 }
 set quadratic(t) {
  this._quadratic = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    quadratic: this._quadratic
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get cutoff() {
  return this._cutoff;
 }
 set cutoff(t) {
  this._cutoff = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    cutoff: this._cutoff
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get outerCutoff() {
  return this._outerCutoff;
 }
 set outerCutoff(t) {
  this._outerCutoff = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    outerCutoff: this._outerCutoff
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get direction() {
  return this._direction;
 }
 set direction(t) {
  this._direction = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    direction: this._direction
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get shadowNear() {
  return this.cameraGroup.children[0].near;
 }
 set shadowNear(t) {
  this.cameraGroup.children[0].near = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    shadowNear: this.cameraGroup.children[0].near
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get shadowFar() {
  return this.cameraGroup.children[0].far;
 }
 set shadowFar(t) {
  this.cameraGroup.children[0].far = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    shadowFar: this.cameraGroup.children[0].far
   }
  }, this._onChangeListener.objectUpdate(t));
 }
 get fov() {
  return this.cameraGroup.children[0].fov;
 }
 set fov(t) {
  t !== this.cameraGroup.children[0].fov && (this.cameraGroup.children[0].fov = t, 
  this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    fov: this.cameraGroup.children[0].fov
   }
  }, this._onChangeListener.objectUpdate(t));
 }
}

class CubeTexture extends Texture {
 static DEFAULT_IMAGES = {
  right: null,
  left: null,
  top: null,
  bottom: null,
  front: null,
  back: null
 };
 constructor(t = {}) {
  super(null, t.wrapS, t.wrapT, t.minFilter, t.magFilter, t.internalFormat, t.format, t.type, t.size, t.size), 
  this._uuid = _Math.generateUUID(), this._wrapR = void 0 !== t.wrapR ? t.wrapR : Texture.WRAPPING.ClampToEdgeWrapping, 
  this.images = void 0 !== t.images ? t.images : CubeTexture.DEFAULT_IMAGES, this.flipy = !1;
 }
 get images() {
  return this._images;
 }
 set images(t) {
  this._images = t, this._dirty = !0;
 }
 get wrapR() {
  return this._wrapR;
 }
 set wrapR(t) {
  t !== this._wrapR && (this._wrapR = t, this._dirty = !0);
 }
 applyConfig(t) {
  super.applyConfig(t), this.wrapR = t.wrapR;
 }
}

class MeshLambertMaterial extends Material {
 constructor() {
  super(Material), this.type = "MeshLambertMaterial", this._color = new Color(16777215 * Math.random()), 
  this._emissive = new Color(0 * Math.random()), this.programName = "lambert";
 }
 set color(t) {
  this._color = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    color: this._color.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 set emissive(t) {
  this._emissive = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    emissive: this._emissive.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 get color() {
  return this._color;
 }
 get emissive() {
  return this._emissive;
 }
 resetProgramFlagsAndValues() {
  super.resetProgramFlagsAndValues();
 }
 requiredProgram(t = void 0) {
  return null === this.requiredProgramTemplate && (this.resetProgramFlagsAndValues(), 
  this.requiredProgramTemplate = new MaterialProgramTemplate(this.programName2, this.flags, this.values, t)), 
  this.requiredProgramTemplate;
 }
 toJson() {
  var t = super.toJson();
  return t.color = this._color.getHex(), t.emissive = this._emissive.getHex(), t;
 }
 static fromJson(t) {
  var e = new MeshPhongMaterial();
  return (e = super.fromJson(t, e))._color = new Color(t.color), e._emissive = new Color(t.emissive), 
  e;
 }
 update(t) {
  for (var e in super.update(t), t) switch (e) {
  case "color":
   this._color.setHex(t.color), delete t.color;
   break;

  case "emissive":
   this._emissive.setHex(t.emissive), delete t.emissive;
  }
 }
}

class SpriteBasicMaterial extends CustomShaderMaterial {
 constructor(t = {}) {
  super(), this.type = "SpriteBasicMaterial", this.programName = "basic_sprite", 
  this.emissive = t.emissive || new Color(0 * Math.random()), this.color = t.color || new Color(16777215 * Math.random()), 
  this.drawCircles = t.drawCircles || !1, this._spriteSize = new Vector2(1, 1), 
  this.setUniform("spriteSize", t.spriteSize || [ 1, 1 ]), this.setUniform("MODE", t.mode || SPRITE_SPACE_SCREEN), 
  this.setAttribute("deltaOffset", t.baseGeometry ? SpriteBasicMaterial._setupDeltaDirections(t.baseGeometry) : null);
 }
 get spriteSize() {
  return this._spriteSize;
 }
 set spriteSize(t) {
  t.equals(this._spriteSize) || (this._spriteSize = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    spriteSize: this._spriteSize
   }
  }, this._onChangeListener.materialUpdate(t)));
 }
 get emissive() {
  return this._emissive;
 }
 set emissive(t) {
  this._emissive = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    emissive: this._emissive.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 get color() {
  return this._color;
 }
 set color(t) {
  this._color = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    color: this._color.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 update(t) {
  for (var e in super.update(t), t) switch (e) {
  case "emissive":
   this._emissive = t.emissive, delete t.emissive;
   break;

  case "color":
   this._color = t.color, delete t.color;
   break;

  case "spriteSize":
   this._spriteSize = t.spriteSize, delete t.spriteSize;
  }
 }
 static _setupDeltaDirections(t) {
  if (t.indices) {
   var e = t.indices, i = new Array(2 * e.count() * 4);
   for (let t = 0; t < e.count(); t++) i[8 * t + 0] = -1, i[8 * t + 1] = 1, i[8 * t + 2] = -1, 
   i[8 * t + 3] = -1, i[8 * t + 4] = 1, i[8 * t + 5] = 1, i[8 * t + 6] = 1, i[8 * t + 7] = -1;
   return new Float32Attribute(i, 2);
  }
  var r = t.vertices, s = new Array(2 * r.count() * 4);
  for (let t = 0; t < r.count(); t++) s[8 * t + 0] = -1, s[8 * t + 1] = 1, s[8 * t + 2] = -1, 
  s[8 * t + 3] = -1, s[8 * t + 4] = 1, s[8 * t + 5] = 1, s[8 * t + 6] = 1, s[8 * t + 7] = -1;
  return new Float32Attribute(s, 2);
 }
}

class StripeBasicMaterial extends CustomShaderMaterial {
 constructor() {
  super(), this.type = "StripeBasicMaterial", this.programName = "basic_stripe", 
  this._color = new Color(16777215 * Math.random()), this._emissive = new Color(0 * Math.random()), 
  this._lineWidth = 1;
 }
 get lineWidth() {
  return this._lineWidth;
 }
 set lineWidth(t) {
  t !== this._lineWidth && (this._lineWidth = t, this._onChangeListener) && (t = {
   uuid: this._uuid,
   changes: {
    lineWidth: this._lineWidth
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 get color() {
  return this._color;
 }
 set color(t) {
  this._color = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    color: this._color.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 get emissive() {
  return this._emissive;
 }
 set emissive(t) {
  t.equals(this._emissive) || (this._emissive = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    emissive: this._emissive.getHex()
   }
  }, this._onChangeListener.materialUpdate(t)));
 }
 update(t) {
  for (var e in super.update(t), t) switch (e) {
  case "color":
   this._color = t.color, delete t.color;
   break;

  case "emissive":
   this._emissive = t.emissive, delete t.emissive;
   break;

  case "lineWidth":
   this._lineWidth = t.lineWidth, delete t.lineWidth;
  }
 }
}

class StripesBasicMaterial extends StripeBasicMaterial {
 constructor(t = {}) {
  super(), this.type = "StripesBasicMaterial", this.programName = "basic_stripes", 
  this.color = t.color || new Color(16777215 * Math.random()), this.emissive = t.emissive || new Color(16777215 * Math.random()), 
  this.lineWidth = void 0 !== t.lineWidth ? t.lineWidth : 1, this.mode = void 0 !== t.mode ? t.mode : STRIPE_SPACE_SCREEN, 
  this.prevVertex = void 0 !== t.baseGeometry ? StripesBasicMaterial._setupPrevVertices(t.baseGeometry) : null, 
  this.nextVertex = void 0 !== t.baseGeometry ? StripesBasicMaterial._setupNextVertices(t.baseGeometry) : null, 
  this.deltaOffset = void 0 !== t.baseGeometry ? StripesBasicMaterial._setupDeltaDirections(t.baseGeometry) : null;
 }
 get lineWidth() {
  return this._lineWidth;
 }
 set lineWidth(t) {
  this._lineWidth = t, this.setUniform("halfLineWidth", t / 2);
 }
 get mode() {
  return this._mode;
 }
 set mode(t) {
  this._mode = t, this.setUniform("MODE", t);
 }
 get prevVertex() {
  return this._prevVertex;
 }
 set prevVertex(t) {
  this._prevVertex = t, this.setAttribute("prevVertex", t);
 }
 get nextVertex() {
  return this._nextVertex;
 }
 set nextVertex(t) {
  this._nextVertex = t, this.setAttribute("nextVertex", t);
 }
 get deltaOffset() {
  return this._deltaOffset;
 }
 set deltaOffset(t) {
  this._deltaOffset = t, this.setAttribute("deltaOffset", t);
 }
 static _setupPrevVertices(t) {
  if (t.indices) {
   var e = t.vertices, i = t.indices, r = new Array(2 * i.count() * 3);
   for (let t = 0; t < i.count(); t++) t % 2 == 0 ? (r[3 * t * 2 + 0] = e.array[3 * i.array[+t] + 0], 
   r[3 * t * 2 + 1] = e.array[3 * i.array[+t] + 1], r[3 * t * 2 + 2] = e.array[3 * i.array[+t] + 2], 
   r[3 * t * 2 + 3] = e.array[3 * i.array[+t] + 0], r[3 * t * 2 + 4] = e.array[3 * i.array[+t] + 1], 
   r[3 * t * 2 + 5] = e.array[3 * i.array[+t] + 2]) : (r[3 * t * 2 + 0] = e.array[3 * i.array[t - 1] + 0], 
   r[3 * t * 2 + 1] = e.array[3 * i.array[t - 1] + 1], r[3 * t * 2 + 2] = e.array[3 * i.array[t - 1] + 2], 
   r[3 * t * 2 + 3] = e.array[3 * i.array[t - 1] + 0], r[3 * t * 2 + 4] = e.array[3 * i.array[t - 1] + 1], 
   r[3 * t * 2 + 5] = e.array[3 * i.array[t - 1] + 2]);
   return new Float32Attribute(r, 3);
  }
  var s = t.vertices, a = new Array(2 * s.count() * 3);
  for (let t = 0; t < s.count(); t++) t % 2 == 0 ? (a[3 * t * 2 + 0] = s.array[3 * +t + 0], 
  a[3 * t * 2 + 1] = s.array[3 * +t + 1], a[3 * t * 2 + 2] = s.array[3 * +t + 2], 
  a[3 * t * 2 + 3] = s.array[3 * +t + 0], a[3 * t * 2 + 4] = s.array[3 * +t + 1], 
  a[3 * t * 2 + 5] = s.array[3 * +t + 2]) : (a[3 * t * 2 + 0] = s.array[3 * (t - 1) + 0], 
  a[3 * t * 2 + 1] = s.array[3 * (t - 1) + 1], a[3 * t * 2 + 2] = s.array[3 * (t - 1) + 2], 
  a[3 * t * 2 + 3] = s.array[3 * (t - 1) + 0], a[3 * t * 2 + 4] = s.array[3 * (t - 1) + 1], 
  a[3 * t * 2 + 5] = s.array[3 * (t - 1) + 2]);
  return new Float32Attribute(a, 3);
 }
 static _setupNextVertices(t) {
  if (t.indices) {
   var e = t.vertices, i = t.indices, r = new Array(2 * i.count() * 3);
   for (let t = 0; t < i.count(); t++) t % 2 == 0 ? (r[3 * t * 2 + 0] = e.array[3 * i.array[t + 1] + 0], 
   r[3 * t * 2 + 1] = e.array[3 * i.array[t + 1] + 1], r[3 * t * 2 + 2] = e.array[3 * i.array[t + 1] + 2], 
   r[3 * t * 2 + 3] = e.array[3 * i.array[t + 1] + 0], r[3 * t * 2 + 4] = e.array[3 * i.array[t + 1] + 1], 
   r[3 * t * 2 + 5] = e.array[3 * i.array[t + 1] + 2]) : (r[3 * t * 2 + 0] = e.array[3 * i.array[t + 0] + 0], 
   r[3 * t * 2 + 1] = e.array[3 * i.array[t + 0] + 1], r[3 * t * 2 + 2] = e.array[3 * i.array[t + 0] + 2], 
   r[3 * t * 2 + 3] = e.array[3 * i.array[t + 0] + 0], r[3 * t * 2 + 4] = e.array[3 * i.array[t + 0] + 1], 
   r[3 * t * 2 + 5] = e.array[3 * i.array[t + 0] + 2]);
   return new Float32Attribute(r, 3);
  }
  var s = t.vertices, a = new Array(2 * s.count() * 3);
  for (let t = 0; t < s.count(); t += 1) t % 2 == 0 ? (a[3 * t * 2 + 0] = s.array[3 * (t + 1) + 0], 
  a[3 * t * 2 + 1] = s.array[3 * (t + 1) + 1], a[3 * t * 2 + 2] = s.array[3 * (t + 1) + 2], 
  a[3 * t * 2 + 3] = s.array[3 * (t + 1) + 0], a[3 * t * 2 + 4] = s.array[3 * (t + 1) + 1], 
  a[3 * t * 2 + 5] = s.array[3 * (t + 1) + 2]) : (a[3 * t * 2 + 0] = s.array[3 * (t + 0) + 0], 
  a[3 * t * 2 + 1] = s.array[3 * (t + 0) + 1], a[3 * t * 2 + 2] = s.array[3 * (t + 0) + 2], 
  a[3 * t * 2 + 3] = s.array[3 * (t + 0) + 0], a[3 * t * 2 + 4] = s.array[3 * (t + 0) + 1], 
  a[3 * t * 2 + 5] = s.array[3 * (t + 0) + 2]);
  return new Float32Attribute(a, 3);
 }
 static _setupDeltaDirections(t) {
  if (t.indices) {
   var e = t.indices, i = new Array(2 * e.count() * 2);
   for (let t = 0; t < e.count(); t++) i[4 * t + 0] = t % 2 == 0 ? -1 : 1, i[4 * t + 1] = 1, 
   i[4 * t + 2] = t % 2 == 0 ? -1 : 1, i[4 * t + 3] = -1;
   return new Float32Attribute(i, 2);
  }
  var r = t.vertices, s = new Array(2 * r.count() * 2);
  for (let t = 0; t < r.count(); t++) s[4 * t + 0] = t % 2 == 0 ? -1 : 1, s[4 * t + 1] = 1, 
  s[4 * t + 2] = t % 2 == 0 ? -1 : 1, s[4 * t + 3] = -1;
  return new Float32Attribute(s, 2);
 }
}

class PointBasicMaterial extends MeshBasicMaterial {
 constructor(t = {}) {
  super(t), this.type = "PointBasicMaterial", this.usePoints = t.usePoints || !0, 
  this.pointSize = t.pointSize || 1, this.drawCircles = t.drawCircles || !1;
 }
}

class Text2DMaterial extends CustomShaderMaterial {
 constructor(t = "text2D", e = {}, i = {}, r = {}) {
  super(t, e, i), this.type = "Text2DMaterial", this.color = r.color || new Color(0, 0, 0);
 }
 get color() {
  return this._color;
 }
 set color(t) {
  this._color = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    color: this._color.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
}

class Circle extends Mesh {
 constructor(t, e, i, r) {
  var s = t || 1, a = e && 10 < e ? e : 10;
  if (void 0 === r) {
   for (var n = 2 * Math.PI / a, o = [], h = [], u = 0; u < a; u++) o.push(Math.cos(u * n) * s), 
   o.push(Math.sin(u * n) * s), o.push(0), h.push(u, (u + 1) % a, a);
   o.push(0, 0, 0), (r = new Geometry()).vertices = Float32Attribute(o, 3), r.indices = Uint32Attribute(h, 1), 
   r.computeVertexNormals();
  }
  super(r, i), this._n = a, this._radius = s, this.type = "Circle";
 }
 setVerticesColors(t, e, i, r) {
  var s = [];
  void 0 === i && (i = 1), void 0 === r && (r = 1);
  for (var a = 0; a < this._n; a++) s.push(e.r, e.g, e.b, r);
  s.push(t.r, t.g, t.b, i), this._geometry.vertColor = Float32Attribute(s, 4);
 }
 toJson() {
  var t = super.toJson();
  return t.n = this._n, t.radius = this._radius, t;
 }
 static fromJson(t, e, i) {
  i = new Circle(t.n, t.radius, i, e);
  return super.fromJson(t, void 0, void 0, i);
 }
}

class Quad extends Mesh {
 constructor(t, e, i, r, s = !1) {
  super(r = void 0 === r ? Quad.makeGeometry(t, e, s) : r, i), this._xy0 = t, this._xy1 = e, 
  this.type = "Quad";
 }
 static makeGeometry(t, e, i, r = !0, s = !0) {
  var a = new Geometry();
  return i ? (a.vertices = Float32Attribute([ t.x, t.y, 0, e.x, t.y, 0, e.x, e.y, 0, t.x, e.y, 0 ], 3), 
  a.indices = Uint32Attribute([ 0, 1, 2, 0, 2, 3 ], 1), a.uv = Float32Attribute([ 0, 0, 1, 0, 1, 1, 0, 1 ], 2)) : (a.vertices = Float32Attribute([ t.x, e.y, 0, e.x, t.y, 0, t.x, t.y, 0, e.x, e.y, 0 ], 3), 
  a.indices = Uint32Attribute([ 0, 1, 2, 0, 3, 1 ], 1), a.uv = Float32Attribute([ 0, 0, 1, 1, 0, 1, 1, 0 ], 2)), 
  s && (a.vertColor = Float32Attribute([ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ], 4)), 
  r && a.computeVertexNormals(), a;
 }
 toJson() {
  var t = super.toJson();
  return t.xy0 = this._xy0, t.xy1 = this._xy1, t;
 }
 static fromJson(t, e, i) {
  i = new Quad(t.xy0, t.xy1, i, e);
  return super.fromJson(t, void 0, void 0, i);
 }
}

class Sprite extends Quad {
 constructor(t = {}) {
  super(null, null, t.material, t.geometry), this.type = "Sprite";
 }
}

class SpriteGeometry extends Geometry {
 constructor(t = {}) {
  super(), this.type = "SpriteGeometry", t.baseGeometry.normals || t.baseGeometry.computeVertexNormals(), 
  this.vertices = SpriteGeometry._setupVertices(t.baseGeometry), this.indices = SpriteGeometry._setupIndices(t.baseGeometry), 
  this.normals = SpriteGeometry._setupNormals(t.baseGeometry);
 }
 static _setupVertices(t) {
  if (t.indices) {
   var e = t.vertices, i = t.indices, r = new Array(i.count() * e.itemSize * 4);
   for (let t = 0; t < i.count(); t++) r[12 * t + 0] = e.array[3 * i.array[t] + 0], 
   r[12 * t + 1] = e.array[3 * i.array[t] + 1], r[12 * t + 2] = e.array[3 * i.array[t] + 2], 
   r[12 * t + 3] = e.array[3 * i.array[t] + 0], r[12 * t + 4] = e.array[3 * i.array[t] + 1], 
   r[12 * t + 5] = e.array[3 * i.array[t] + 2], r[12 * t + 6] = e.array[3 * i.array[t] + 0], 
   r[12 * t + 7] = e.array[3 * i.array[t] + 1], r[12 * t + 8] = e.array[3 * i.array[t] + 2], 
   r[12 * t + 9] = e.array[3 * i.array[t] + 0], r[12 * t + 10] = e.array[3 * i.array[t] + 1], 
   r[12 * t + 11] = e.array[3 * i.array[t] + 2];
   return new Float32Attribute(r, e.itemSize);
  }
  var s = t.vertices, a = new Array(s.count() * s.itemSize * 4);
  for (let t = 0; t < s.count(); t++) a[12 * t + 0] = s.array[3 * t + 0], a[12 * t + 1] = s.array[3 * t + 1], 
  a[12 * t + 2] = s.array[3 * t + 2], a[12 * t + 3] = s.array[3 * t + 0], a[12 * t + 4] = s.array[3 * t + 1], 
  a[12 * t + 5] = s.array[3 * t + 2], a[12 * t + 6] = s.array[3 * t + 0], a[12 * t + 7] = s.array[3 * t + 1], 
  a[12 * t + 8] = s.array[3 * t + 2], a[12 * t + 9] = s.array[3 * t + 0], a[12 * t + 10] = s.array[3 * t + 1], 
  a[12 * t + 11] = s.array[3 * t + 2];
  return new Float32Attribute(a, s.itemSize);
 }
 static _setupIndices(t) {
  if (t.indices) {
   var e = t.indices, i = new Array(6 * e.count());
   for (let t = 0; t < e.count(); t++) i[6 * t + 0] = 2 * (2 * t + 0) + 0, i[6 * t + 1] = 2 * (2 * t + 0) + 1, 
   i[6 * t + 2] = 2 * (2 * t + 1) + 0, i[6 * t + 3] = 2 * (2 * t + 1) + 1, i[6 * t + 4] = 2 * (2 * t + 1) + 0, 
   i[6 * t + 5] = 2 * (2 * t + 0) + 1;
   return new Uint32Attribute(i, 1);
  }
  var r = t.vertices, s = new Array(6 * r.count());
  for (let t = 0; t < r.count(); t++) s[6 * t + 0] = 2 * (2 * t + 0) + 0, s[6 * t + 1] = 2 * (2 * t + 0) + 1, 
  s[6 * t + 2] = 2 * (2 * t + 1) + 0, s[6 * t + 3] = 2 * (2 * t + 1) + 1, s[6 * t + 4] = 2 * (2 * t + 1) + 0, 
  s[6 * t + 5] = 2 * (2 * t + 0) + 1;
  return new Uint32Attribute(s, 1);
 }
 static _setupNormals(t) {
  if (t.indices) {
   var e = t.indices, i = t.normals, r = new Array(e.count() * i.itemSize * 4);
   for (let t = 0; t < e.count(); t++) r[12 * t + 0] = i.array[3 * e.array[t] + 0], 
   r[12 * t + 1] = i.array[3 * e.array[t] + 1], r[12 * t + 2] = i.array[3 * e.array[t] + 2], 
   r[12 * t + 3] = i.array[3 * e.array[t] + 0], r[12 * t + 4] = i.array[3 * e.array[t] + 1], 
   r[12 * t + 5] = i.array[3 * e.array[t] + 2], r[12 * t + 6] = i.array[3 * e.array[t] + 0], 
   r[12 * t + 7] = i.array[3 * e.array[t] + 1], r[12 * t + 8] = i.array[3 * e.array[t] + 2], 
   r[12 * t + 9] = i.array[3 * e.array[t] + 0], r[12 * t + 10] = i.array[3 * e.array[t] + 1], 
   r[12 * t + 11] = i.array[3 * e.array[t] + 2];
   return new Float32Attribute(r, e.itemSize);
  }
  var s = t.vertices, a = t.normals, n = new Array(s.count() * a.itemSize * 4);
  for (let t = 0; t < s.count(); t++) n[12 * t + 0] = a.array[3 * t + 0], n[12 * t + 1] = a.array[3 * t + 1], 
  n[12 * t + 2] = a.array[3 * t + 2], n[12 * t + 3] = a.array[3 * t + 0], n[12 * t + 4] = a.array[3 * t + 1], 
  n[12 * t + 5] = a.array[3 * t + 2], n[12 * t + 6] = a.array[3 * t + 0], n[12 * t + 7] = a.array[3 * t + 1], 
  n[12 * t + 8] = a.array[3 * t + 2], n[12 * t + 9] = a.array[3 * t + 0], n[12 * t + 10] = a.array[3 * t + 1], 
  n[12 * t + 11] = a.array[3 * t + 2];
  return new Float32Attribute(n, a.itemSize);
 }
 static _setupCenters(t) {
  if (t.indices) {
   var e = t.vertices, i = t.indices, r = new Array(i.count() * e.itemSize * 4);
   for (let t = 0; t < i.count(); t++) r[12 * t + 0] = e.array[3 * i.array[t] + 0], 
   r[12 * t + 1] = e.array[3 * i.array[t] + 1], r[12 * t + 2] = e.array[3 * i.array[t] + 2], 
   r[12 * t + 3] = e.array[3 * i.array[t] + 0], r[12 * t + 4] = e.array[3 * i.array[t] + 1], 
   r[12 * t + 5] = e.array[3 * i.array[t] + 2], r[12 * t + 6] = e.array[3 * i.array[t] + 0], 
   r[12 * t + 7] = e.array[3 * i.array[t] + 1], r[12 * t + 8] = e.array[3 * i.array[t] + 2], 
   r[12 * t + 9] = e.array[3 * i.array[t] + 0], r[12 * t + 10] = e.array[3 * i.array[t] + 1], 
   r[12 * t + 11] = e.array[3 * i.array[t] + 2];
   return new Float32Attribute(r, e.itemSize);
  }
  var s = t.vertices, a = new Array(s.count() * s.itemSize * 4);
  for (let t = 0; t < s.count(); t++) a[12 * t + 0] = s.array[3 * t + 0], a[12 * t + 1] = s.array[3 * t + 1], 
  a[12 * t + 2] = s.array[3 * t + 2], a[12 * t + 3] = s.array[3 * t + 0], a[12 * t + 4] = s.array[3 * t + 1], 
  a[12 * t + 5] = s.array[3 * t + 2], a[12 * t + 6] = s.array[3 * t + 0], a[12 * t + 7] = s.array[3 * t + 1], 
  a[12 * t + 8] = s.array[3 * t + 2], a[12 * t + 9] = s.array[3 * t + 0], a[12 * t + 10] = s.array[3 * t + 1], 
  a[12 * t + 11] = s.array[3 * t + 2];
  return new Float32Attribute(a, s.itemSize);
 }
}

class Stripe extends Mesh {
 constructor(t, e = new StripeBasicMaterial(), i = new PickingShaderMaterial("stripe"), r = !1, s = 8) {
  Array.isArray(t) && (t = new Float32Attribute(t, 3)), r && (t = _perp(t, s));
  var r = new Geometry(), s = _setupIndex(t), a = _setupVertex(t);
  r.indices = new Uint32Attribute(s, 1), r.vertices = new Float32Attribute(a.stripePositions, t.itemSize), 
  e.setAttribute("prevPosition", new Float32Attribute(a.stripePrevPosition, t.itemSize)), 
  e.setAttribute("nextPosition", new Float32Attribute(a.stripeNextPosition, t.itemSize)), 
  e.setAttribute("normalDirection", new Float32Attribute(a.stripeNormalDirection, 1)), 
  e.setUniform("lineWidth", 1), super(r, e, i), this.type = "Stripe", this._dashed = !1;
 }
 set dashed(t) {
  this._dashed = t;
 }
 get dashed() {
  return this._dashed;
 }
}

function _setupIndex(e) {
 var i = [];
 for (let t = 0; t < 2 * e.count() - 2; t++) t % 2 == 0 ? (i.push(t + 0), i.push(t + 1), 
 i.push(t + 2)) : (i.push(t + 0), i.push(t + 2), i.push(t + 1));
 return i;
}

function _setupVertex(e) {
 var i = new Array(e.count() * e.itemSize * 2), r = new Array(e.count() * e.itemSize * 2), s = new Array(e.count() * e.itemSize * 2), a = new Array(2 * e.count());
 for (let t = 0; t < e.count(); t++) i[t * e.itemSize * 2 + 0] = e.array[t * e.itemSize + 0], 
 i[t * e.itemSize * 2 + 1] = e.array[t * e.itemSize + 1], i[t * e.itemSize * 2 + 2] = e.array[t * e.itemSize + 2], 
 i[t * e.itemSize * 2 + 3] = e.array[t * e.itemSize + 0], i[t * e.itemSize * 2 + 4] = e.array[t * e.itemSize + 1], 
 i[t * e.itemSize * 2 + 5] = e.array[t * e.itemSize + 2], 0 === t ? (r[t * e.itemSize * 2 + 0] = e.array[t * e.itemSize + 0], 
 r[t * e.itemSize * 2 + 1] = e.array[t * e.itemSize + 1], r[t * e.itemSize * 2 + 2] = e.array[t * e.itemSize + 2], 
 r[t * e.itemSize * 2 + 3] = e.array[t * e.itemSize + 0], r[t * e.itemSize * 2 + 4] = e.array[t * e.itemSize + 1], 
 r[t * e.itemSize * 2 + 5] = e.array[t * e.itemSize + 2], s[t * e.itemSize * 2 + 0] = e.array[t * e.itemSize + e.itemSize + 0], 
 s[t * e.itemSize * 2 + 1] = e.array[t * e.itemSize + e.itemSize + 1], s[t * e.itemSize * 2 + 2] = e.array[t * e.itemSize + e.itemSize + 2], 
 s[t * e.itemSize * 2 + 3] = e.array[t * e.itemSize + e.itemSize + 0], s[t * e.itemSize * 2 + 4] = e.array[t * e.itemSize + e.itemSize + 1], 
 s[t * e.itemSize * 2 + 5] = e.array[t * e.itemSize + e.itemSize + 2]) : 1 <= t && t <= e.count() - 2 ? (r[t * e.itemSize * 2 + 0] = e.array[t * e.itemSize - e.itemSize + 0], 
 r[t * e.itemSize * 2 + 1] = e.array[t * e.itemSize - e.itemSize + 1], r[t * e.itemSize * 2 + 2] = e.array[t * e.itemSize - e.itemSize + 2], 
 r[t * e.itemSize * 2 + 3] = e.array[t * e.itemSize - e.itemSize + 0], r[t * e.itemSize * 2 + 4] = e.array[t * e.itemSize - e.itemSize + 1], 
 r[t * e.itemSize * 2 + 5] = e.array[t * e.itemSize - e.itemSize + 2], s[t * e.itemSize * 2 + 0] = e.array[t * e.itemSize + e.itemSize + 0], 
 s[t * e.itemSize * 2 + 1] = e.array[t * e.itemSize + e.itemSize + 1], s[t * e.itemSize * 2 + 2] = e.array[t * e.itemSize + e.itemSize + 2], 
 s[t * e.itemSize * 2 + 3] = e.array[t * e.itemSize + e.itemSize + 0], s[t * e.itemSize * 2 + 4] = e.array[t * e.itemSize + e.itemSize + 1], 
 s[t * e.itemSize * 2 + 5] = e.array[t * e.itemSize + e.itemSize + 2]) : t === e.count() - 1 && (r[t * e.itemSize * 2 + 0] = e.array[t * e.itemSize - e.itemSize + 0], 
 r[t * e.itemSize * 2 + 1] = e.array[t * e.itemSize - e.itemSize + 1], r[t * e.itemSize * 2 + 2] = e.array[t * e.itemSize - e.itemSize + 2], 
 r[t * e.itemSize * 2 + 3] = e.array[t * e.itemSize - e.itemSize + 0], r[t * e.itemSize * 2 + 4] = e.array[t * e.itemSize - e.itemSize + 1], 
 r[t * e.itemSize * 2 + 5] = e.array[t * e.itemSize - e.itemSize + 2], s[t * e.itemSize * 2 + 0] = e.array[t * e.itemSize + 0], 
 s[t * e.itemSize * 2 + 1] = e.array[t * e.itemSize + 0 + 1], s[t * e.itemSize * 2 + 2] = e.array[t * e.itemSize + 0 + 2], 
 s[t * e.itemSize * 2 + 3] = e.array[t * e.itemSize + 0], s[t * e.itemSize * 2 + 4] = e.array[t * e.itemSize + 0 + 1], 
 s[t * e.itemSize * 2 + 5] = e.array[t * e.itemSize + 0 + 2]), a[2 * t + 0] = 1, 
 a[2 * t + 1] = -1;
 return {
  stripePositions: i,
  stripePrevPosition: r,
  stripeNextPosition: s,
  stripeNormalDirection: a
 };
}

function _perp(a, t) {
 var n = [];
 for (let s = 0; s <= 1; s += 1 / t) {
  let e = 0, i = 0, r = 0;
  for (let t = 0; t < a.count(); t++) {
   var o = _bint(t, a.count() - 1, s);
   e += a.array[t * a.itemSize + 0] * o, i += a.array[t * a.itemSize + 1] * o, r += a.array[t * a.itemSize + 2] * o;
  }
  n.push(e, i, r);
 }
 return a.array = n, a;
}

function _bint(t, e, i) {
 return _binomial(e, t) * Math.pow(i, t) * Math.pow(1 - i, e - t);
}

function _binomial(t, e) {
 if ("number" != typeof t || "number" != typeof e) return !1;
 for (var i = 1, r = t - e + 1; r <= t; r++) i *= r;
 for (r = 1; r <= e; r++) i /= r;
 return i;
}

class Stripes extends Mesh {
 constructor(t = {}) {
  super(t.geometry, t.material, t.pickingMaterial), this.type = "Stripes", this.GBufferMaterial = void 0 !== t.GBufferMaterial ? t.GBufferMaterial : Stripes.assembleGBufferMaterial({
   baseMaterial: this.material
  }), this._dashed = !1;
 }
 get material() {
  return super.material;
 }
 set material(t) {
  super.material = t, this.GBufferMaterial.setUniform("halfLineWidth", this.material.lineWidth / 2), 
  this.GBufferMaterial.setUniform("MODE", this.material.mode), this.GBufferMaterial.setAttribute("prevVertex", this.material.prevVertex), 
  this.GBufferMaterial.setAttribute("nextVertex", this.material.nextVertex), this.GBufferMaterial.setAttribute("deltaOffset", this.material.deltaOffset);
 }
 get GBufferMaterial() {
  return super.GBufferMaterial;
 }
 set GBufferMaterial(t) {
  super.GBufferMaterial = t;
 }
 set dashed(t) {
  this._dashed = t;
 }
 get dashed() {
  return this._dashed;
 }
 static assembleGBufferMaterial(t) {
  return new CustomShaderMaterial("GBuffer_stripes", {
   halfLineWidth: t.baseMaterial.lineWidth / 2,
   MODE: t.baseMaterial.mode
  }, {
   prevVertex: t.baseMaterial.prevVertex,
   nextVertex: t.baseMaterial.nextVertex,
   deltaOffset: t.baseMaterial.deltaOffset
  });
 }
}

class StripesGeometry extends Geometry {
 constructor(t = {}) {
  super(), this.type = "StripesGeometry", this.vertices = StripesGeometry._setupVertices(t.baseGeometry), 
  this.indices = StripesGeometry._setupIndices(t.baseGeometry);
 }
 static _setupVertices(t) {
  if (t.indices) {
   var e = t.vertices, i = t.indices, r = new Array(2 * i.count() * 3);
   for (let t = 0; t < i.count(); t++) r[3 * t * 2 + 0] = e.array[3 * i.array[t] + 0], 
   r[3 * t * 2 + 1] = e.array[3 * i.array[t] + 1], r[3 * t * 2 + 2] = e.array[3 * i.array[t] + 2], 
   r[3 * t * 2 + 3] = e.array[3 * i.array[t] + 0], r[3 * t * 2 + 4] = e.array[3 * i.array[t] + 1], 
   r[3 * t * 2 + 5] = e.array[3 * i.array[t] + 2];
   return new Float32Attribute(r, 3);
  }
  var s = t.vertices, a = new Array(2 * s.count() * 3);
  for (let t = 0; t < s.count(); t++) a[3 * t * 2 + 0] = s.array[3 * t + 0], a[3 * t * 2 + 1] = s.array[3 * t + 1], 
  a[3 * t * 2 + 2] = s.array[3 * t + 2], a[3 * t * 2 + 3] = s.array[3 * t + 0], 
  a[3 * t * 2 + 4] = s.array[3 * t + 1], a[3 * t * 2 + 5] = s.array[3 * t + 2];
  return new Float32Attribute(a, 3);
 }
 static _setupIndices(t) {
  if (t.indices) {
   var e = t.indices, i = new Array(3 * e.count());
   for (let t = 0; t < e.count(); t += 2) i[3 * t + 0] = 2 * (t + 0) + 0, i[3 * t + 1] = 2 * (t + 0) + 1, 
   i[3 * t + 2] = 2 * (t + 1) + 0, i[3 * t + 3] = 2 * (t + 1) + 1, i[3 * t + 4] = 2 * (t + 1) + 0, 
   i[3 * t + 5] = 2 * (t + 0) + 1;
   return new Uint32Attribute(i, 1);
  }
  var r = t.vertices, s = new Array(3 * r.count());
  for (let t = 0; t < r.count(); t += 2) s[3 * t + 0] = 2 * (t + 0) + 0, s[3 * t + 1] = 2 * (t + 0) + 1, 
  s[3 * t + 2] = 2 * (t + 1) + 0, s[3 * t + 3] = 2 * (t + 1) + 1, s[3 * t + 4] = 2 * (t + 1) + 0, 
  s[3 * t + 5] = 2 * (t + 0) + 1;
  return new Uint32Attribute(s, 1);
 }
}

class Text2D extends Mesh {
 constructor(t = {}) {
  super(), this.type = "Text2D", this.frustumCulled = !1, this.pickable = !1, this._text = void 0 !== t.text ? t.text : "New text", 
  this._fontTexture = void 0 !== t.fontTexture ? t.fontTexture : null, this._xPos = void 0 !== t.xPos ? t.xPos : 0, 
  this._yPos = void 0 !== t.yPos ? t.yPos : 0, this._fontSize = void 0 !== t.fontSize ? t.fontSize : 32, 
  this._cellAspect = void 0 !== t.cellAspect ? t.cellAspect : 1, this._mode = void 0 !== t.mode ? t.mode : TEXT2D_SPACE_SCREEN, 
  this._mode === TEXT2D_SPACE_SCREEN ? (this.geometry = this.setText2D(this._text, this._xPos, this._yPos, this._fontSize), 
  this.material = new Text2DMaterial(), this.material.setAttribute("deltaOffset", new Float32Attribute([])), 
  this.material.setUniform("MODE", TEXT2D_SPACE_SCREEN), this.material.addMap(this._fontTexture)) : this._mode === TEXT2D_SPACE_WORLD ? (this.geometry = Text2D._assembleGeometry({
   text: this._text
  }), this.material = Text2D._assembleMaterial({
   text: this._text,
   fontSize: this._fontSize,
   cellAspect: this._cellAspect,
   offset: new Vector2(this._xPos, this._yPos),
   mode: this._mode
  }), this.material.addMap(this._fontTexture)) : console.error("[" + this.type + "]: Unknow mode [" + t.mode + "]"), 
  this.material.transparent = !0;
 }
 set text(t) {
  this._text = t, this.geometry = this.setText2D(this._text, this._xPos, this._yPos, this._fontSize);
 }
 get text() {
  return this._text;
 }
 set fontTexture(t) {
  this._fontTexture = t, this.material.clearMaps(), this.material.addMap(this._fontTexture);
 }
 get fontTexture() {
  return this._fontTexture;
 }
 set xPos(t) {
  this._xPos = t;
 }
 get xPos() {
  return this._xPos;
 }
 set yPos(t) {
  this._yPos = t;
 }
 get yPos() {
  return this._yPos;
 }
 set fontSize(t) {
  this._fontSize = t;
 }
 get fontSize() {
  return this._fontSize;
 }
 static _assembleGeometry(t) {
  var e = new Geometry();
  return e.vertices = Text2D._setupVertices(t.text), e.indices = Text2D._setupIndices(t.text), 
  e.uv = Text2D._setupUVs(t.text), e;
 }
 static _setupVertices(e) {
  var i = new Array(4 * e.length * 2);
  for (let t = 0; t < e.length; t++) i[4 * t * 2 + 0] = 0, i[4 * t * 2 + 1] = 0, 
  i[4 * t * 2 + 2] = 0, i[4 * t * 2 + 3] = 0, i[4 * t * 2 + 4] = 0, i[4 * t * 2 + 5] = 0, 
  i[4 * t * 2 + 6] = 0, i[4 * t * 2 + 7] = 0;
  return new Float32Attribute(i, 2);
 }
 static _setupIndices(e) {
  var i = new Array(6 * e.length);
  for (let t = 0; t < e.length; t++) i[6 * t + 0] = 2 * (2 * t + 0) + 0, i[6 * t + 1] = 2 * (2 * t + 0) + 1, 
  i[6 * t + 2] = 2 * (2 * t + 1) + 0, i[6 * t + 3] = 2 * (2 * t + 1) + 1, i[6 * t + 4] = 2 * (2 * t + 1) + 0, 
  i[6 * t + 5] = 2 * (2 * t + 0) + 1;
  return new Uint32Attribute(i, 1);
 }
 static _setupUVs(e) {
  var i = new Array(4 * e.length * 2);
  for (let t = 0; t < e.length; t++) {
   var r = e.charAt(t), s = r.charCodeAt() % 16 / 16, r = Math.floor(r.charCodeAt() / 16) / 16, a = new Vector2(s, 1 - r), n = new Vector2(s, 1 - (r + 1 / 16)), o = new Vector2(s + 1 / 16, 1 - r), s = new Vector2(s + 1 / 16, 1 - (r + 1 / 16));
   i[4 * t * 2 + 0] = a.x, i[4 * t * 2 + 1] = a.y, i[4 * t * 2 + 2] = n.x, i[4 * t * 2 + 3] = n.y, 
   i[4 * t * 2 + 4] = o.x, i[4 * t * 2 + 5] = o.y, i[4 * t * 2 + 6] = s.x, i[4 * t * 2 + 7] = s.y;
  }
  return new Float32Attribute(i, 2);
 }
 static _assembleMaterial(t) {
  var e = new Text2DMaterial();
  return e.setAttribute("deltaOffset", Text2D._setupDeltaDirections(t.text, t.fontSize, t.cellAspect, t.offset)), 
  e.setUniform("MODE", t.mode), e;
 }
 static _setupCenterOffsets(e) {
  var i = new Array(4 * e.length * 2);
  for (let t = 0; t < e.length; t++) i[4 * t * 2 + 0] = t, i[4 * t * 2 + 1] = 0, 
  i[4 * t * 2 + 2] = t, i[4 * t * 2 + 3] = 0, i[4 * t * 2 + 4] = t, i[4 * t * 2 + 5] = 0, 
  i[4 * t * 2 + 6] = t, i[4 * t * 2 + 7] = 0;
  return new Float32Attribute(i, 2);
 }
 static _setupPositionIdentifiers(e) {
  var i = new Array(4 * e.length * 2);
  for (let t = 0; t < e.length; t++) i[4 * t * 2 + 0] = -1, i[4 * t * 2 + 1] = 1, 
  i[4 * t * 2 + 2] = -1, i[4 * t * 2 + 3] = -1, i[4 * t * 2 + 4] = 1, i[4 * t * 2 + 5] = 1, 
  i[4 * t * 2 + 6] = 1, i[4 * t * 2 + 7] = -1;
  return new Float32Attribute(i, 2);
 }
 static _setupDeltaDirections(e, i, r, s) {
  var a = new Array(4 * e.length * 2);
  for (let t = 0; t < e.length; t++) a[4 * t * 2 + 0] = -1 * i / 2 * r + t * i * r + s.x, 
  a[4 * t * 2 + 1] = +i / 2 + 0 * i + s.y, a[4 * t * 2 + 2] = -1 * i / 2 * r + t * i * r + s.x, 
  a[4 * t * 2 + 3] = -1 * i / 2 + 0 * i + s.y, a[4 * t * 2 + 4] = +i / 2 * r + t * i * r + s.x, 
  a[4 * t * 2 + 5] = +i / 2 + 0 * i + s.y, a[4 * t * 2 + 6] = +i / 2 * r + t * i * r + s.x, 
  a[4 * t * 2 + 7] = -1 * i / 2 + 0 * i + s.y;
  return new Float32Attribute(a, 2);
 }
 setText2D(e, i, r, s) {
  var a = new Array(), n = new Array();
  for (let t = 0; t < e.length; t++) {
   var o = new Vector2(i + t * s, r + s), h = new Vector2(i + t * s + s, r + s), u = new Vector2(i + t * s, r), l = new Vector2(i + t * s + s, r), o = (a.push(o.x, o.y), 
   a.push(u.x, u.y), a.push(h.x, h.y), a.push(h.x, h.y), a.push(u.x, u.y), a.push(l.x, l.y), 
   e.charAt(t)), h = o.charCodeAt() % 16 / 16, u = Math.floor(o.charCodeAt() / 16) / 16, l = new Vector2(h, 1 - u), o = new Vector2(h + 1 / 16, 1 - u), _ = new Vector2(h, 1 - (u + 1 / 16)), h = new Vector2(h + 1 / 16, 1 - (u + 1 / 16));
   n.push(l.x, l.y), n.push(_.x, _.y), n.push(o.x, o.y), n.push(o.x, o.y), n.push(_.x, _.y), 
   n.push(h.x, h.y);
  }
  var t = new Geometry();
  return t.vertices = new Float32Attribute(a, 2), t.uv = new Float32Attribute(n, 2), 
  t;
 }
}

class Grid extends Mesh {
 constructor(t, e, i = 1, r = 10, s = 128, a) {
  super(t, e), this.type = "Grid", this.pickable = !1, this.frustumCulled = !1, 
  this._plane = new Plane(new Vector3(0, 1, 0), 0), this._n = s * (1 / i), this.geometry = new Geometry(), 
  this.geometry.vertices = new Float32Attribute(this._generateLinePositionsAttribute().concat(this._generateLinePositionsAttribute()), 3), 
  this.material = new CustomShaderMaterial("grid", {
   "plane.normal": this._plane.normal.toArray(),
   "plane.constant": this._plane.constant,
   unitSize: i,
   orderOfMagnitude: r,
   LColor: [ .5, .5, .5 ],
   UColor: [ .5, .5, .5 ],
   lineBase: this._n
  }, {
   VIDLU: new Float32Attribute(this._generateLineIDsAttribute(0).concat(this._generateLineIDsAttribute(1)), 1),
   offset: new Float32Attribute(this._generateLineOffsetAttribute(1).concat(this._generateLineOffsetAttribute(1)), 3)
  }), this.material.transparent = !0, this.material.lights = !1, this.renderingPrimitive = LINES;
 }
 _generateLines() {
  var e = [], i = 2048;
  e.push(-i, 0, 0, i, 0, 0);
  for (let t = -1; -64 <= t; t--) e.push(-i, 0, 9 * t, i, 0, 9 * t);
  for (let t = 1; t <= 64; t++) e.push(-i, 0, 9 * t, i, 0, 9 * t);
  e.push(0, 0, -i, 0, 0, i);
  for (let t = -1; -64 <= t; t--) e.push(9 * t, 0, -i, 9 * t, 0, i);
  for (let t = 1; t <= 64; t++) e.push(9 * t, 0, -i, 9 * t, 0, i);
  return e;
 }
 _generateLineIDsAttribute(e) {
  var i = new Array(), r = this._n;
  i.push(e, e);
  for (let t = -1; t >= -r; t--) i.push(e, e);
  for (let t = 1; t <= r; t++) i.push(e, e);
  i.push(e, e);
  for (let t = -1; t >= -r; t--) i.push(e, e);
  for (let t = 1; t <= r; t++) i.push(e, e);
  return i;
 }
 _generateLinePositionsAttribute() {
  var e = new Array(), i = this._n;
  e.push(-1, 0, 0, 1, 0, 0);
  for (let t = -1; t >= -i; t--) e.push(-1, 0, 0, 1, 0, 0);
  for (let t = 1; t <= i; t++) e.push(-1, 0, 0, 1, 0, 0);
  e.push(0, 0, -1, 0, 0, 1);
  for (let t = -1; t >= -i; t--) e.push(0, 0, -1, 0, 0, 1);
  for (let t = 1; t <= i; t++) e.push(0, 0, -1, 0, 0, 1);
  return e;
 }
 _generateLineOffsetAttribute(e = 1) {
  var i = new Array(), r = this._n;
  i.push(0, 0, 0, 0, 0, 0);
  for (let t = -1; t >= -r; t--) i.push(0, 0, t * e, 0, 0, t * e);
  for (let t = 1; t <= r; t++) i.push(0, 0, t * e, 0, 0, t * e);
  i.push(0, 0, 0, 0, 0, 0);
  for (let t = -1; t >= -r; t--) i.push(t * e, 0, 0, t * e, 0, 0);
  for (let t = 1; t <= r; t++) i.push(t * e, 0, 0, t * e, 0, 0);
  return i;
 }
}

class ZSpriteBasicMaterial extends CustomShaderMaterial {
 constructor(t = {}) {
  super(), this.type = "ZSpriteBasicMaterial", this.programName = "basic_zsprite", 
  this.setUniform("SpriteMode", "SpriteMode" in t ? t.SpriteMode : SPRITE_SPACE_SCREEN), 
  this.setUniform("SpriteSize", "SpriteSize" in t ? t.SpriteSize : [ 1, 1 ]), this.color = t.color || new Color(16777215 * Math.random()), 
  this.emissive = t.emissive || new Color(0 * Math.random()), this.diffuse = t.diffuse || new Color(16777215 * Math.random());
 }
 clone_for_picking() {
  var t = new ZSpriteBasicMaterial({
   SpriteMode: this.getUniform("SpriteMode"),
   SpriteSize: this.getUniform("SpriteSize"),
   color: this.color,
   emissive: this.emissive,
   diffuse: this.diffuse
  });
  for (const e of this.maps) t.addMap(e);
  return t._instanceData = this._instanceData, t.addSBFlag("PICK_MODE_UINT"), t.setUniform("u_PickInstance", !1), 
  t;
 }
 clone_for_outline() {
  var t = new ZSpriteBasicMaterial({
   SpriteMode: this.getUniform("SpriteMode"),
   SpriteSize: this.getUniform("SpriteSize"),
   color: this.color,
   emissive: this.emissive,
   diffuse: this.diffuse
  });
  for (const e of this.maps) t.addMap(e);
  return t._instanceData = this._instanceData, t.addSBFlag("OUTLINE"), t.setUniform("u_OutlineGivenInstances", !1), 
  t.setAttribute("a_OutlineInstances", Int32Attribute([ 0 ], 1, 2147483647)), t;
 }
 get color() {
  return this._color;
 }
 set color(t) {
  this._color = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    color: this._color.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 get emissive() {
  return this._emissive;
 }
 set emissive(t) {
  this._emissive = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    emissive: this._emissive.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 get diffuse() {
  return this._diffuse;
 }
 set diffuse(t) {
  this._diffuse = t, this._onChangeListener && (t = {
   uuid: this._uuid,
   changes: {
    diffuse: this._diffuse.getHex()
   }
  }, this._onChangeListener.materialUpdate(t));
 }
 outline_instances_setup(t) {
  this.setUniform("u_OutlineGivenInstances", !0);
  var e = this.getAttribute("a_OutlineInstances");
  e.array = new Int32Array(t), e.divisor = 1;
 }
 outline_instances_reset() {
  this.setUniform("u_OutlineGivenInstances", !1);
  var t = this.getAttribute("a_OutlineInstances");
  t.array = new Int32Array([ 0 ]), t.divisor = 2147483647;
 }
 update(t) {
  for (var e in super.update(t), t) switch (e) {
  case "color":
   this._color = t.color, delete t.color;
   break;

  case "emissive":
   this._emissive = t.emissive, delete t.emissive;
   break;

  case "diffuse":
   this._diffuse = t.diffuse, delete t.diffuse;
  }
 }
}

class ZSprite extends Mesh {
 constructor(t = null, e = null) {
  null === t && (i = new Vector2(-.5, .5), r = new Vector2(.5, -.5), t = Quad.makeGeometry(i, r, !1, !1, !1));
  var i = (e = null === e ? new ZSpriteBasicMaterial() : e).clone_for_picking(), r = e.clone_for_outline();
  super(t, e, i, r), this.type = "ZSprite";
 }
}

class ShaderBuilder {
 constructor() {
  this._LOGTAG = "ShaderBuilder: ", this._templatesCache = {}, this._multiLineCommentRegex = /\/\*[^*]*(?:\*+[^*\/][^*]*)*\*\//g, 
  this._singleLineCommentRegex = /\/\/.*/g, this._lineReduceRegex = /[^\r\n]+/g, 
  this._prefixSuffixSpaceTrimRegex = /(^\s+|\s+$)/g, this._multipleSpaceMatch = /\s+/g;
 }
 _generateShaderName(t, e) {
  for (var i = t.sort(), r = Object.keys(e).sort(), s = "", a = 0; a < i.length; a++) s += i[a].toLowerCase();
  for (a = 0; a < r.length; a++) s += r[a] + e[r[a]];
  return s;
 }
 hasTemplate(t) {
  return void 0 !== this._templatesCache[t];
 }
 buildTemplateTree(t, e) {
  if (!this.hasTemplate(t)) {
   for (var i = (e = e.replace(this._multiLineCommentRegex, "")).match(this._lineReduceRegex), r = new ShaderBuilder.RootNode(), s = 0; s < i.length; s++) {
    var a = i[s].replace(this._prefixSuffixSpaceTrimRegex, "").replace(this._multipleSpaceMatch, " ").replace(this._singleLineCommentRegex, "");
    if (0 !== a.length) try {
     r.parseLine(a);
    } catch (t) {
     return console.error(this._LOGTAG + "Exception occurred while building the template tree (" + t + ")\nProblematic line: " + i[s].replace(this._prefixSuffixSpaceTrimRegex, "")), 
     !1;
    }
   }
   return r.validate() ? (this._templatesCache[t] = {
    cachedShaders: {},
    tree: r
   }, !0) : (console.error(this._LOGTAG + "Warning the commands are not properly closed!"), 
   !1);
  }
  console.log(this._LOGTAG + "Warning. Overwriting the template tree!", t);
 }
 fetchShader(t, e, i) {
  var t = this._templatesCache[t], r = this._generateShaderName(e, i);
  if (void 0 !== t) {
   var s = t.cachedShaders, a = s[r];
   if (void 0 !== a) return a;
   try {
    var n = t.tree.build(e, i);
    return s[r] = n;
   } catch (t) {
    console.error(this._LOGTAG + "Exception occurred while building the shader (" + t + ")");
   }
  } else console.log(this._LOGTAG + "Could not find the shader template!");
 }
}

ShaderBuilder.STATE_OPENED = 0, ShaderBuilder.STATE_CLOSED = 1, ShaderBuilder.commandRegex = /#for.*|#end.*|#if.*|#else.*|#fi.*/i, 
ShaderBuilder.nodeStartRegex = /#for.*|#if.*/i, ShaderBuilder.forLoopStartRegex = /#for\s+[a-zA-Z0-9_]*\s+in\s+[a-zA-Z0-9_]*\s+to\s+[a-zA-Z0-9_]*/i, 
ShaderBuilder.forLoopVariableRegex = /#for\s+([a-zA-Z0-9_]+)\s+in\s+([a-zA-Z0-9_]+)\s+to\s+([a-zA-Z0-9_]+)/i, 
ShaderBuilder.endforRegex = /^#end$/i, ShaderBuilder.prefixSuffixSpaceRegex = /(^\s+|\s+$)/g, 
ShaderBuilder.ifRegex = /#if.*/i, ShaderBuilder.elseIfRegex = /#else\s+if.*/i, ShaderBuilder.elseRegex = /^#else$/i, 
ShaderBuilder.fiRegex = /^#fi$/i, ShaderBuilder.validConditionShellRegex = /\((?:[a-zA-Z0-9!()\s_]+|&&|\|\|)+\)/i, 
ShaderBuilder.logicalOperatorsRegex = /\&\&|[|]{2}/g, ShaderBuilder.everythingButBracketsRegex = /[^()!]+/g, 
ShaderBuilder.isPosInt = /0|[1-9][0-9]*/, ShaderBuilder.Node = class {
 constructor() {
  this._state = ShaderBuilder.STATE_OPENED;
 }
 get state() {
  return this._state;
 }
 set state(t) {
  this._state = t;
 }
 parseLine(t) {}
 _createNewSubNode(t) {
  if (ShaderBuilder.commandRegex.test(t)) {
   if (ShaderBuilder.ifRegex.test(t)) {
    var e = t.substring(3).replace(ShaderBuilder.prefixSuffixSpaceRegex, "");
    if (ShaderBuilder.validConditionShellRegex.test(e)) return ShaderBuilder.ConditionNode.evaluateCondition(e, []), 
    new ShaderBuilder.ConditionNode(e);
    throw "Badly formed condition";
   }
   if (ShaderBuilder.forLoopStartRegex.test(t)) {
    e = ShaderBuilder.forLoopVariableRegex.exec(t);
    if (4 != e.length) throw "Badly formed command";
    return new ShaderBuilder.LoopNode(e[1], e[2], e[3]);
   }
   throw "Badly formed command";
  }
  return new ShaderBuilder.CodeNode(t);
 }
 build(t, e) {
  return "";
 }
 validate() {
  return !1;
 }
}, ShaderBuilder.RootNode = class extends ShaderBuilder.Node {
 constructor() {
  super(), this._subNodes = [];
 }
 parseLine(t) {
  if (0 < this._subNodes.length) {
   var e = this._subNodes[this._subNodes.length - 1];
   if (e instanceof ShaderBuilder.CodeNode) if (ShaderBuilder.commandRegex.test(t)) {
    if (!ShaderBuilder.nodeStartRegex.test(t)) throw "Unexpected Command";
    this._subNodes.push(this._createNewSubNode(t));
   } else e.parseLine(t); else e.state === ShaderBuilder.STATE_OPENED ? e.parseLine(t) : this._subNodes.push(this._createNewSubNode(t));
  } else this._subNodes.push(this._createNewSubNode(t));
 }
 build(t, e) {
  for (var i, r, s = "", a = 0; a < this._subNodes.length; a++) s += this._subNodes[a].build(t, e);
  for (i in "\n" === s.substring(s.length - 1) && (s = s.slice(0, -1)), e) e.hasOwnProperty(i) && (r = new RegExp("##" + i, "g"), 
  s = s.replace(r, e[i]));
  return s;
 }
 validate() {
  for (var t = 0; t < this._subNodes.length; t++) if (!this._subNodes[t].validate()) return !1;
  return !0;
 }
}, ShaderBuilder.CodeNode = class extends ShaderBuilder.Node {
 constructor(t) {
  super(), this._code = t + "\n", this._state = ShaderBuilder.STATE_CLOSED;
 }
 parseLine(t) {
  this._code += t + "\n";
 }
 build(t, e) {
  return this._code;
 }
 validate() {
  return !0;
 }
}, ShaderBuilder.ConditionNode = class extends ShaderBuilder.Node {
 constructor(t) {
  super(), this._if_condition = t, this._if_subNodes = [], this._elseif_conditions = [], 
  this._elseif_subNodesList = [], this._else_subNodes = null;
 }
 static evaluateCondition(condition, flags) {
  if (condition = condition.replace(/\s/g, ""), 0 < flags.length) {
   for (var trueFlagsStr = "", falseFlagsStr = "", i = 0; i < flags.length; i++) trueFlagsStr += flags[i], 
   falseFlagsStr += "!" + flags[i], i !== flags.length - 1 && (trueFlagsStr += "|", 
   falseFlagsStr += "|");
   condition = condition.replace(new RegExp(falseFlagsStr, "gi"), "false"), condition = condition.replace(new RegExp(trueFlagsStr, "gi"), "true");
  }
  var condValues = condition.split(ShaderBuilder.logicalOperatorsRegex), condOperators = condition.match(ShaderBuilder.logicalOperatorsRegex);
  if (null == condOperators && (condOperators = []), 0 === condValues.length || condOperators.length !== condValues.length - 1) throw "BadlyFormedCondition";
  for (var i = 0; i < condValues.length; i++) {
   var value = condValues[i].match(ShaderBuilder.everythingButBracketsRegex)[0].replace(ShaderBuilder.prefixSuffixSpaceRegex, "");
   "true" !== value && (condValues[i] = condValues[i].replace(ShaderBuilder.everythingButBracketsRegex, "false"));
  }
  condition = condValues[0];
  for (var i = 0; i < condOperators.length; i++) condition += condOperators[i] + condValues[i + 1];
  try {
   return eval(condition);
  } catch (e) {
   throw "BadlyFormedCondition";
  }
 }
 _fetchSubNodes() {
  return null !== this._else_subNodes ? this._else_subNodes : 0 !== this._elseif_conditions.length ? this._elseif_subNodesList[this._elseif_subNodesList.length - 1] : this._if_subNodes;
 }
 parseLine(t) {
  var e = this._fetchSubNodes();
  if (0 < e.length) {
   var i = e[e.length - 1];
   if (i.state === ShaderBuilder.STATE_OPENED) i.parseLine(t); else if (ShaderBuilder.commandRegex.test(t)) if (ShaderBuilder.nodeStartRegex.test(t)) e.push(this._createNewSubNode(t)); else if (ShaderBuilder.elseIfRegex.test(t)) {
    if (null !== this._else_subNodes) throw "UnexpectedElseIfCondition";
    var r = t.substring(8).replace(ShaderBuilder.prefixSuffixSpaceRegex, "");
    if (!ShaderBuilder.validConditionShellRegex.test(r)) throw "BadlyFormedCondition";
    ShaderBuilder.ConditionNode.evaluateCondition(r, []), this._elseif_conditions.push(r), 
    this._elseif_subNodesList.push([]);
   } else if (ShaderBuilder.elseRegex.test(t)) this._else_subNodes = []; else {
    if (!ShaderBuilder.fiRegex.test(t) || i._state !== ShaderBuilder.STATE_CLOSED) throw "UnexpectedBlockClosure";
    this._state = ShaderBuilder.STATE_CLOSED;
   } else i instanceof ShaderBuilder.CodeNode ? i.parseLine(t) : e.push(this._createNewSubNode(t));
  } else ShaderBuilder.fiRegex.test(t) ? this._state = ShaderBuilder.STATE_CLOSED : e.push(this._createNewSubNode(t));
 }
 build(t, e) {
  var i = null, r = "";
  if (ShaderBuilder.ConditionNode.evaluateCondition(this._if_condition, t)) i = this._if_subNodes; else {
   for (var s = 0; s < this._elseif_conditions.length; s++) if (ShaderBuilder.ConditionNode.evaluateCondition(this._elseif_conditions[s], t)) {
    i = this._elseif_subNodesList[s];
    break;
   }
   if (null === (i = null === i && null !== this._else_subNodes ? this._else_subNodes : i)) return "";
  }
  for (s = 0; s < i.length; s++) r += i[s].build(t, e);
  return r;
 }
 validate() {
  if (this._state !== ShaderBuilder.STATE_CLOSED) return !1;
  for (var t = 0; t < this._if_subNodes.length; t++) if (!this._if_subNodes[t].validate()) return !1;
  for (t = 0; t < this._elseif_subNodesList.length; t++) for (var e = this._elseif_subNodesList[t], i = 0; i < e.length; i++) if (!e[i].validate()) return !1;
  if (null !== this._else_subNodes) for (t = 0; t < this._else_subNodes.length; t++) if (!this._else_subNodes[t].validate()) return !1;
  return !0;
 }
}, ShaderBuilder.LoopNode = class extends ShaderBuilder.Node {
 constructor(t, e, i) {
  super(), this._macro = t, this._from = e, this._to = i, this._subNodes = [];
 }
 parseLine(t) {
  if (0 < this._subNodes.length) {
   var e = this._subNodes[this._subNodes.length - 1];
   if (e instanceof ShaderBuilder.CodeNode) if (ShaderBuilder.commandRegex.test(t)) if (ShaderBuilder.nodeStartRegex.test(t)) this._subNodes.push(this._createNewSubNode(t)); else {
    if (!ShaderBuilder.endforRegex.test(t)) throw "Unexpected Command";
    this._state = ShaderBuilder.STATE_CLOSED;
   } else e.parseLine(t); else e.state === ShaderBuilder.STATE_OPENED ? e.parseLine(t) : ShaderBuilder.endforRegex.test(t) ? this._state = ShaderBuilder.STATE_CLOSED : this._subNodes.push(this._createNewSubNode(t));
  } else ShaderBuilder.endforRegex.test(t) ? this._state = ShaderBuilder.STATE_CLOSED : this._subNodes.push(this._createNewSubNode(t));
 }
 build(t, e) {
  var i, r;
  if (ShaderBuilder.isPosInt.test(this._from)) i = parseInt(this._from, 10); else {
   if (void 0 === e[this._from]) throw "For loop parameter [" + this._from + "] not specified.";
   i = e[this._from];
  }
  if (ShaderBuilder.isPosInt.test(this._to)) r = parseInt(this._to, 10); else {
   if (void 0 === e[this._to]) throw "For loop parameter [" + this._to + "] not specified.";
   r = e[this._to];
  }
  if (!Number.isInteger(i) || !Number.isInteger(r) || i < 0 || r < 0) throw "Invalid for loop parameters.";
  for (var s = "", a = 0; a < this._subNodes.length; a++) s += this._subNodes[a].build(t, e);
  var n = "", o = new RegExp("##" + this._macro, "g");
  if (i < r) for (a = i; a < r; a++) n += s.replace(o, a); else for (a = i; r < a; a--) n += s.replace(o, a);
  return n;
 }
 validate() {
  if (this._state !== ShaderBuilder.STATE_CLOSED) return !1;
  for (var t = 0; t < this._subNodes.length; t++) if (!this._subNodes[t].validate()) return !1;
  return !0;
 }
};

class GLProgram {
 constructor(t) {
  this._gl = t, this._program = this._gl.createProgram(), this._initialized = !1, 
  this._attributeSetter = null, this._uniformSetter = null;
 }
 attachShader(t) {
  this._gl.attachShader(this._program, t);
 }
 get glProgram() {
  return this._program;
 }
 get initialized() {
  return this._initialized;
 }
 get attributeSetter() {
  return this._attributeSetter;
 }
 get uniformSetter() {
  return this._uniformSetter;
 }
 set initialized(t) {
  this._initialized = t;
 }
 set uniformSetter(t) {
  this._uniformSetter = t;
 }
 set attributeSetter(t) {
  this._attributeSetter = t;
 }
 use() {
  this._gl.useProgram(this._program);
 }
}

class GLProgramManager {
 constructor(t) {
  this._glManager = t, this._gl = t.context, this._shaderBuilder = new ShaderBuilder(), 
  this._compiledPrograms = {};
 }
 isTemplateDownloaded(t) {
  return this._shaderBuilder.hasTemplate(t + VERTEX_SHADER) && this._shaderBuilder.hasTemplate(t + FRAGMENT_SHADER);
 }
 addTemplate(t) {
  var e = t.id, i = t.sources, r = Object.keys(i);
  for (let t = 0; t < r.length; t++) this._shaderBuilder.buildTemplateTree(e + r[t], i[r[t]]);
 }
 fetchProgram(t, e, i, r) {
  var s = t.programID + "NUM_DLIGHTS" + e + "NUM_PLIGHTS" + i + "NUM_SLIGHTS" + r, a = this._compiledPrograms[s];
  if (void 0 !== a) return a;
  a = new GLProgram(this._gl), t.values.NUM_DLIGHTS = e, t.values.NUM_PLIGHTS = i, 
  t.values.NUM_SLIGHTS = r, e + i === 0 && t.flags.push("NO_LIGHTS"), 0 < e && t.flags.push("DLIGHTS"), 
  0 < i && t.flags.push("PLIGHTS"), 0 < r && t.flags.push("SLIGHTS");
  var n, e = this._shaderBuilder.fetchShader(t.name + VERTEX_SHADER, t.flags, t.values), i = this._shaderBuilder.fetchShader(t.name + FRAGMENT_SHADER, t.flags, t.values);
  if (void 0 !== e && void 0 !== i) return r = this._compileShader(e, this._gl.VERTEX_SHADER), 
  t = this._compileShader(i, this._gl.FRAGMENT_SHADER), a.attachShader(r), a.attachShader(t), 
  this._gl.linkProgram(a.glProgram), this._gl.getProgramParameter(a.glProgram, this._gl.LINK_STATUS) || (n = this._gl.getProgramInfoLog(a.glProgram), 
  console.error("Could not compile WebGL program. \n\n" + n), console.log("VERTEX SHADER:\n" + e + "\n\n\n"), 
  console.log("FRAGMENT SHADER:\n" + i)), this._gl.deleteShader(r), this._gl.deleteShader(t), 
  a.attributeSetter = this._initAttributeSetter(a.glProgram), a.uniformSetter = this._initUniformSetter(a.glProgram), 
  a.initialized = !0, this._compiledPrograms[s] = a;
  console.error("FAILED TO BUILD SHADER PROGRAM!");
 }
 _initAttributeSetter(t) {
  for (var e = {}, h = this, i = this._gl.getProgramParameter(t, this._gl.ACTIVE_ATTRIBUTES), r = 0; r < i; r++) {
   var s = this._gl.getActiveAttrib(t, r);
   const u = h._gl.getAttribLocation(t, s.name);
   var a = this._gl, n = s.type;
   let o;
   o = n == a.INT || n == a.INT_VEC2 || n == a.INT_VEC3 || n == a.GL_INT_VEC4 ? a.INT : (a.UNSIGNED_INT, 
   n == a.UNSIGNED_INT_VEC2 || n == a.UNSIGNED_INT_VEC3 || n == a.UNSIGNED_INT_VEC4 ? a.UNSIGNED_INT : a.FLOAT), 
   e[s.name] = {}, e[s.name].set = function(e, i, r = !1, s = 0, a = 0, n = !1) {
    var t = h._glManager.getGLBuffer(e);
    if (0 == a && (a = o), i <= 4) e.locations.push(u), h._gl.enableVertexAttribArray(u), 
    h._gl.bindBuffer(h._gl.ARRAY_BUFFER, t), o == h._gl.FLOAT ? h._gl.vertexAttribPointer(u, i, a, n, 0, 0) : h._gl.vertexAttribIPointer(u, i, a, 0, 0), 
    r ? h._gl.vertexAttribDivisor(u, s) : h._gl.vertexAttribDivisor(u, 0); else {
     h._gl.bindBuffer(h._gl.ARRAY_BUFFER, t);
     for (let t = 0; t < i / 4; t++) e.locations.push(u + t), h._gl.enableVertexAttribArray(u + t), 
     o == h._gl.FLOAT ? h._gl.vertexAttribPointer(u + t, 4, a, n, 64, 16 * t) : h._gl.vertexAttribIPointer(u + t, 4, a, 64, 16 * t), 
     r ? h._gl.vertexAttribDivisor(u + t, s) : h._gl.vertexAttribDivisor(u + t, 0);
    }
   }, e[s.name].free = function() {
    h._gl.disableVertexAttribArray(u);
   };
  }
  return e;
 }
 _initUniformSetter(e) {
  var i = {}, r = this, s = this._gl.getProgramParameter(e, this._gl.ACTIVE_UNIFORMS);
  i.__validation = {
   uniforms: {},
   reset() {
    for (var t in this.uniforms) this.uniforms.hasOwnProperty(t) && (this.uniforms[t] = !1);
   },
   validate() {
    var t, e = [];
    for (t in this.uniforms) this.uniforms.hasOwnProperty(t) && !this.uniforms[t] && e.push(t);
    return e;
   }
  };
  for (let t = 0; t < s; t++) {
   const a = r._gl.getActiveUniform(e, t), n = r._gl.getUniformLocation(e, a.name);
   if (n) switch (i[a.name] = {}, i.__validation.uniforms[a.name] = !1, a.type) {
   case r._gl.FLOAT:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform1fv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform1f(n, t), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.FLOAT_VEC2:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform2fv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform2f(n, t[0], t[1]), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.FLOAT_VEC3:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform3fv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform3f(n, t[0], t[1], t[2]), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.FLOAT_VEC4:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform4fv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform4f(n, t[0], t[1], t[2], t[3]), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.FLOAT_MAT3:
    i[a.name].set = function(t) {
     r._gl.uniformMatrix3fv(n, !1, t), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.FLOAT_MAT4:
    i[a.name].set = function(t) {
     r._gl.uniformMatrix4fv(n, !1, t), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.INT:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform1iv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform1i(n, t), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.UNSIGNED_INT:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform1uiv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform1ui(n, t), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.INT_VEC2:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform2iv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform2i(n, t[0], t[1]), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.INT_VEC3:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform3iv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform3i(n, t[0], t[1], t[2]), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.INT_VEC4:
    1 < a.size ? i[a.name].set = function(t) {
     r._gl.uniform4iv(n, t), i.__validation.uniforms[a.name] = !0;
    } : i[a.name].set = function(t) {
     r._gl.uniform4i(n, t[0], t[1], t[2], t[3]), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.BOOL:
    i[a.name].set = function(t) {
     r._gl.uniform1f(n, t), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.SAMPLER_2D:
   case r._gl.INT_SAMPLER_2D:
   case r._gl.UNSIGNED_INT_SAMPLER_2D:
    i[a.name].set = function(t, e) {
     r._gl.activeTexture(r._gl.TEXTURE0 + e), r._gl.bindTexture(r._gl.TEXTURE_2D, t), 
     r._gl.uniform1i(n, e), i.__validation.uniforms[a.name] = !0;
    };
    break;

   case r._gl.SAMPLER_CUBE:
    i[a.name].set = function(t, e) {
     r._gl.activeTexture(r._gl.TEXTURE0 + e), r._gl.bindTexture(r._gl.TEXTURE_CUBE_MAP, t), 
     r._gl.uniform1i(n, e), i.__validation.uniforms[a.name] = !0;
    };
    break;

   default:
    console.error("UNKNOWN");
   }
  }
  return i;
 }
 _compileShader(t, e) {
  var i = this._gl.createShader(e);
  return this._gl.shaderSource(i, t), this._gl.compileShader(i), this._gl.getShaderParameter(i, this._gl.COMPILE_STATUS) || console.error(this._gl.getShaderInfoLog(i)), 
  "" !== this._gl.getShaderInfoLog(i) && console.warn("WebGLShader: _gl.getShaderInfoLog()", e === this._gl.VERTEX_SHADER ? "vertex" : "fragment", this._gl.getShaderInfoLog(i)), 
  i;
 }
 _getCachedProgram(t) {
  var e = this._compiledPrograms[t];
  return void 0 === e && (e = new GLProgram(this._gl), this._compiledPrograms[t] = e), 
  e;
 }
}

class Renderer {
 constructor(t, e, i) {
  this._glManager = new GLManager(t, e, i), this._canvas = t, this._gl = this._glManager.context, 
  this._glProgramManager = new GLProgramManager(this._glManager), this._shaderLoader = new ShaderLoader(), 
  this._requiredPrograms = new Map(), this._loadingPrograms = new Map(), this._compiledPrograms = new Map(), 
  this._currentRenderTarget = null, this._autoClear = !0, this._selectedRenderer = null, 
  this._uuid = _Math.generateUUID(), this._materialIDMap = new Map(), this._materialID = 0, 
  this._takeScreenshot = !1, this._screenshotInProgress = !1, this._segmentedScreenshot = !1, 
  this._screenshotSizeMultiplier = 1, this._renderQueue = void 0, this._screenshotTextureReference = void 0, 
  this._screenshotData = new Uint8ClampedArray(), this._viewport = {
   xOffset: 0,
   yOffset: 0,
   width: this._canvas.width,
   height: this._canvas.height
  }, this._logLevel = 2;
 }
 render(t, e, i, r = !1, s = 0) {
  e instanceof Camera == !1 ? console.error(LOGTAG + "Given camera is not an instance of Camera") : (null === e.parent && e.updateMatrixWorld(), 
  e.matrixWorldInverse.getInverse(e.matrixWorld), void 0 !== i && this._initRenderTarget(i, r, s), 
  this._glManager.autoClear && this._glManager.clear(!0, !0, !0), this._selectedRenderer(t, e), 
  this._takeScreenshot && (this._takeScreenshot = !1, this._screenshotInProgress = !0, 
  console.log("Taking screenshot..."), r = this._segmentedScreenshot ? this._takeSegmentedScreenshot(t, e, i, this._renderQueue, this._screenshotTextureReference) : this._takeFullScreenshot(this._screenshotTextureReference), 
  this._glManager.openImageInNewTab(r), this._screenshotInProgress = !1), this._currentRenderTarget && (this._cleanupRenderTarget(), 
  this._currentRenderTarget = null));
 }
 _takeFullScreenshot(t = void 0) {
  var e = (t || this.getViewport()).width, i = (t || this.getViewport()).height, r = (this._screenshotData.length !== e * i * 4 && (this._screenshotData = new Uint8ClampedArray(e * i * 4)), 
  t && (r = this._gl.createFramebuffer(), this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, r), 
  r = this._glManager._textureManager.getGLTexture(t), this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.COLOR_ATTACHMENT0, this._gl.TEXTURE_2D, r, 0)), 
  this._gl.readPixels(0, 0, e, i, this._gl.RGBA, this._gl.UNSIGNED_BYTE, this._screenshotData), 
  t && this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, null), this._glManager.flipImage(this._screenshotData, e, i), 
  new ImageData(this._screenshotData, e, i));
  return r;
 }
 _takeSegmentedScreenshot(e, r, s, a = void 0, n = void 0) {
  var o = (n || this.getViewport()).width, h = (n || this.getViewport()).height, u = r.left, l = r.right, i = r.top, _ = r.bottom, c = this._screenshotSizeMultiplier, t = this._screenshotSizeMultiplier, d = (-u + l) / c, m = (i - _) / t, g = new Uint8ClampedArray(o * c * 4 * h * t);
  let p = 0;
  for (let t = i; t > _; t -= m) {
   r.top = t, r.bottom = t - m;
   let i = 0;
   for (let t = u; t < l; t += d) {
    r.left = t, r.right = t + d, a ? a.render() : this.render(e, r, s), console.log("Taking screenshot block...");
    var f = this._takeFullScreenshot(n);
    for (let e = 0; e < h; e++) for (let t = 0; t < 4 * o; t++) g[p * o * c * h * 4 + e * o * c * 4 + i * o * 4 + t] = f.data[e * o * 4 + t];
    i++;
   }
   p++;
  }
  return r.left = u, r.right = l, r.top = i, r.bottom = _, a ? a.render() : this.render(e, r, s), 
  new ImageData(g, o * c, h * t);
 }
 _downloadProgram(e) {
  let i = this;
  const r = e.name;
  this._loadingPrograms.has(e.name) || (2 <= this._logLevel && console.log("(Down)loading: " + e.programID + ": " + r + "."), 
  this._loadingPrograms.set(e.name, e), this._shaderLoader.loadProgramSources(r, function(t) {
   2 <= i._logLevel && console.log("(Down)loaded: " + e.programID + ": " + r + "."), 
   i._glProgramManager.addTemplate(t), i._loadingPrograms.delete(e.name);
  }, void 0, function(t) {
   console.error("Failed to load program: " + e.programID + ": " + r + "."), i._loadingPrograms.delete(e.name);
  }));
 }
 downloadTexture(t, e) {
  return this._glManager.downloadTexture(t, e);
 }
 _loadRequiredPrograms() {
  let t = !0;
  for (var [ e, i ] of this._requiredPrograms) this._glProgramManager.isTemplateDownloaded(i.name) ? (this._compileProgram(i), 
  this._requiredPrograms.delete(e)) : (t = !1, this._downloadProgram(i));
  return t;
 }
 _compileProgram(t) {
  let e = 0, i = 0, r = 0;
  this._lightsCombined && (e = this._lightsCombined.directional.length, i = this._lightsCombined.point.length, 
  r = this._lightsCombined.spot.length);
  var s = this._glProgramManager.fetchProgram(t, e, i, r);
  this._compiledPrograms.set(t.programID, s);
 }
 preDownloadPrograms(e) {
  for (let t = 0; t < e.length; t++) this._glProgramManager.isTemplateDownloaded(e[t]) || this._downloadProgram(e[t]);
 }
 _initRenderTarget(t, e, i) {
  var r = (this._currentRenderTarget = t)._viewport;
  this.updateViewport(r.z, r.w, r.x, r.y), e ? this._glManager.initRenderTargetCube(t, i) : this._glManager.initRenderTarget(t);
 }
 _cleanupRenderTarget() {
  this._currentRenderTarget = null, this.updateViewport(this._canvas.width, this._canvas.height), 
  this._glManager.cleanupRenderTarget();
 }
 dispose() {
  this._glManager.deleteAttributeBuffers(), this._glManager.deleteFrameBuffers(), 
  this._glManager.deleteTextures();
 }
 addShaderLoaderUrls(...t) {
  this._shaderLoader.addUrls(t);
 }
 set autoClear(t) {
  this._autoClear = t;
 }
 get autoClear() {
  return this._autoClear;
 }
 get clearColor() {
  return this._glManager.clearColor;
 }
 set clearColor(t) {
  t = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(t);
  t && this._glManager.setClearColor(parseInt(t[1], 16) / 255, parseInt(t[2], 16) / 255, parseInt(t[3], 16) / 255, parseInt(t[4], 16) / 255);
 }
 updateViewport(t, e, i = 0, r = 0) {
  this._viewport = {
   xOffset: i,
   yOffset: r,
   width: t,
   height: e
  }, this._gl.viewport(i, r, t, e);
 }
 getViewport() {
  return this._viewport;
 }
 get glManager() {
  return this._glManager;
 }
 get gl() {
  return this._glManager.gl;
 }
 get glContextAttributes() {
  return this._glManager.contextAttributes;
 }
 generateMaterialID(t = void 0) {
  var e;
  return void 0 !== t ? this._materialIDMap.has(t) ? this._materialIDMap.get(t) : (e = this._materialID, 
  this._materialIDMap.set(t, e), this._materialID++, e) : this._materialID++;
 }
 takeScreenshot(t = void 0, e = 1, i = !1, r = void 0) {
  this._takeScreenshot = !0, this._segmentedScreenshot = i, this._screenshotSizeMultiplier = e, 
  this._renderQueue = r, this._screenshotTextureReference = t;
 }
 pickRGB(t = void 0, e, i, r) {
  (t || this.getViewport()).width;
  var s, a = (t || this.getViewport()).height, n = new Uint8Array(4);
  return t && (s = this._gl.createFramebuffer(), this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, s), 
  s = this._glManager._textureManager.getGLTexture(t), this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.COLOR_ATTACHMENT0, this._gl.TEXTURE_2D, s, 0)), 
  this._gl.readPixels(e, a - i, 1, 1, this._gl.RGBA, this._gl.UNSIGNED_BYTE, n), 
  t && this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, null), n;
 }
 pickUINT(t = void 0, e, i, r) {
  (t || this.getViewport()).width;
  var s, a = (t || this.getViewport()).height, n = new Uint32Array(4);
  return t && (s = this._gl.createFramebuffer(), this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, s), 
  s = this._glManager._textureManager.getGLTexture(t), this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.COLOR_ATTACHMENT0, this._gl.TEXTURE_2D, s, 0)), 
  this._gl.readPixels(e, a - i, 1, 1, this._gl.RGBA_INTEGER, this._gl.UNSIGNED_INT, n), 
  t && this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, null), n;
 }
}

class RenderTarget {
 constructor(t, e) {
  this._uuid = _Math.generateUUID(), this.type = "RenderTarget", this._width = void 0 !== t ? t : 800, 
  this._height = void 0 !== e ? e : 600, this._viewport = new Vector4(0, 0, t, e), 
  this._drawBuffers = [], this._depthTexture = null;
 }
 get width() {
  return this._width;
 }
 get height() {
  return this._height;
 }
 get depthTexture() {
  return this._depthTexture;
 }
 set width(t) {
  this._width = t, this._viewport = new Vector4(0, 0, this._width, this._height);
 }
 set height(t) {
  this._height = t, this._viewport = new Vector4(0, 0, this._width, this._height);
 }
 set depthTexture(t) {
  this._depthTexture = t;
 }
 addDepthTexture(t = !1) {
  this._depthTexture = t ? new CubeTexture({
   textures: void 0,
   wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
   wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
   wrapR: Texture.WRAPPING.ClampToEdgeWrapping,
   minFilter: Texture.FILTER.NearestFilter,
   magFilter: Texture.FILTER.NearestFilter,
   internalFormat: Texture.FORMAT.DEPTH_COMPONENT32F,
   format: Texture.FORMAT.DEPTH_COMPONENT,
   type: Texture.TYPE.FLOAT,
   size: Math.min(this._width, this._height)
  }) : new Texture(void 0, Texture.WRAPPING.ClampToEdgeWrapping, Texture.WRAPPING.ClampToEdgeWrapping, Texture.FILTER.NearestFilter, Texture.FILTER.NearestFilter, Texture.FORMAT.DEPTH_COMPONENT32F, Texture.FORMAT.DEPTH_COMPONENT, Texture.TYPE.FLOAT, this._width, this._height);
 }
 rmDepthTexture() {
  this._depthTexture = null;
 }
 addDrawBuffer(t) {
  this._drawBuffers.push(t);
 }
 rmDrawBuffer(t) {
  return this._drawBuffers.splice(t, 1);
 }
 getDrawBuffer(t) {
  return this._drawBuffers[t];
 }
 sizeDrawBuffers() {
  return this._drawBuffers.length;
 }
 clearDrawBuffers() {
  this._drawBuffers = [];
 }
}

class RenderPass {
 constructor(t, e, i, r, s, a, n = null, o = [], h = 0) {
  this._type = t, this._isInitialized = !1, this._initialize = e, this._preprocess = i, 
  this._postprocess = r, this._target = s, this._viewport = a, this._outDepthID = n, 
  this._outTextures = o, this._side = h;
 }
 get type() {
  return this._type;
 }
 get initialize() {
  return this._initialize;
 }
 get preprocess() {
  return this._preprocess;
 }
 get postprocess() {
  return this._postprocess;
 }
 get target() {
  return this._target;
 }
 get viewport() {
  return this._viewport;
 }
 get outDepthID() {
  return this._outDepthID;
 }
 get outTextures() {
  return this._outTextures;
 }
 get side() {
  return this._side;
 }
 set type(t) {
  this._type = t;
 }
 set initialize(t) {
  this._initialize = t;
 }
 set preprocess(t) {
  this._preprocess = t;
 }
 set postprocess(t) {
  this._postprocess = t;
 }
 set target(t) {
  this._target = t;
 }
 set viewport(t) {
  this._viewport = t;
 }
 set outDepthID(t) {
  this._type === RenderPass.SCREEN && console.warn("Warning: Setting output depth texture to RenderPass that renders to screen!"), 
  this._outDepthID = t;
 }
 set outTextures(t) {
  this._type === RenderPass.SCREEN && console.warn("Warning: Setting output color textures to RenderPass that renders to screen!"), 
  this._outTextures = t;
 }
 set side(t) {
  this._side = t;
 }
}

RenderPass.BASIC = 0, RenderPass.TEXTURE_MERGE = 1, RenderPass.POSTPROCESS = 2, 
RenderPass.TEXTURE = 3, RenderPass.TEXTURE_CUBE_MAP = 3.2, RenderPass.SCREEN = 4, 
RenderPass.DEFAULT_R8_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.R8,
 format: Texture.FORMAT.RED,
 type: Texture.TYPE.UNSIGNED_BYTE,
 clearFunction: 3
}, RenderPass.DEFAULT_R32I_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.R32I,
 format: Texture.FORMAT.RED_INTEGER,
 type: Texture.TYPE.INT,
 clearFunction: 2
}, RenderPass.DEFAULT_R32UI_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.R32UI,
 format: Texture.FORMAT.RED_INTEGER,
 type: Texture.TYPE.UNSIGNED_INT,
 clearFunction: 1
}, RenderPass.DEFAULT_RGB_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.RGB,
 format: Texture.FORMAT.RGB,
 type: Texture.TYPE.UNSIGNED_BYTE,
 clearFunction: 3
}, RenderPass.DEFAULT_RGBA_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.RGBA,
 format: Texture.FORMAT.RGBA,
 type: Texture.TYPE.UNSIGNED_BYTE,
 clearFunction: 3
}, RenderPass.DEFAULT_RGBA_NEAREST_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.NearestFilter,
 magFilter: Texture.FILTER.NearestFilter,
 internalFormat: Texture.FORMAT.RGBA,
 format: Texture.FORMAT.RGBA,
 type: Texture.TYPE.UNSIGNED_BYTE,
 clearFunction: 3
}, RenderPass.DEFAULT_R16F_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.R16F,
 format: Texture.FORMAT.RED,
 type: Texture.TYPE.HALF_FLOAT,
 clearFunction: 3
}, RenderPass.NEAREST_R16F_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.NearestFilter,
 magFilter: Texture.FILTER.NearestFilter,
 internalFormat: Texture.FORMAT.R16F,
 format: Texture.FORMAT.RED,
 type: Texture.TYPE.HALF_FLOAT,
 clearFunction: 3
}, RenderPass.DEFAULT_R16F_TEXTURE_CUBE_MAP_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapR: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.R16F,
 format: Texture.FORMAT.RED,
 type: Texture.TYPE.HALF_FLOAT,
 clearFunction: 3
}, RenderPass.NEAREST_R16F_TEXTURE_CUBE_MAP_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapR: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.NearestFilter,
 magFilter: Texture.FILTER.NearestFilter,
 internalFormat: Texture.FORMAT.R16F,
 format: Texture.FORMAT.RED,
 type: Texture.TYPE.HALF_FLOAT,
 clearFunction: 3
}, RenderPass.DEFAULT_RGB16F_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.RGB16F,
 format: Texture.FORMAT.RGBA,
 type: Texture.TYPE.HALF_FLOAT,
 clearFunction: 3
}, RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.RGBA16F,
 format: Texture.FORMAT.RGBA,
 type: Texture.TYPE.HALF_FLOAT,
 clearFunction: 3
}, RenderPass.NEAREST_RGBA16F_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.NearestFilter,
 magFilter: Texture.FILTER.NearestFilter,
 internalFormat: Texture.FORMAT.RGBA16F,
 format: Texture.FORMAT.RGBA,
 type: Texture.TYPE.HALF_FLOAT,
 clearFunction: 3
}, RenderPass.FLOAT_RGB_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.RGBA16F,
 format: Texture.FORMAT.RGBA,
 type: Texture.TYPE.HALF_FLOAT,
 clearFunction: 3
}, RenderPass.FULL_FLOAT_RGB_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.RGBA16F,
 format: Texture.FORMAT.RGBA,
 type: Texture.TYPE.FLOAT,
 clearFunction: 3
}, RenderPass.FULL_FLOAT_RGB_NEAREST_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.NearestFilter,
 magFilter: Texture.FILTER.NearestFilter,
 internalFormat: Texture.FORMAT.RGBA16F,
 format: Texture.FORMAT.RGBA,
 type: Texture.TYPE.FLOAT,
 clearFunction: 3
}, RenderPass.FULL_FLOAT_R32F_TEXTURE_CONFIG = {
 wrapS: Texture.WRAPPING.ClampToEdgeWrapping,
 wrapT: Texture.WRAPPING.ClampToEdgeWrapping,
 minFilter: Texture.FILTER.LinearFilter,
 magFilter: Texture.FILTER.LinearFilter,
 internalFormat: Texture.FORMAT.R32F,
 format: Texture.FORMAT.RED,
 type: Texture.TYPE.FLOAT,
 clearFunction: 3
};

class RenderQueue {
 constructor(t) {
  this._renderer = t, this._storedRenderQueues = {}, this._renderQueue = [], this._textureMap = {}, 
  this._forwardedAdditionalData = {}, this._textureMergeScene = new Scene(), this._textureMergeQuad = new Quad(new Vector2(-1, 1), new Vector2(1, -1), new MeshBasicMaterial()), 
  this._textureMergeQuad.frustumCulled = !1, this._textureMergeCamera = new OrthographicCamera(-1, 1, 1, -1, 1, 2), 
  this._textureMergeScene.add(this._textureMergeQuad), this._renderTarget = new RenderTarget(t.width, t.height), 
  this._uuid = _Math.generateUUID();
 }
 _setupRenderTarget(i) {
  var t, r = i.viewport;
  this._renderTarget.clearDrawBuffers(), this._renderTarget.width = r.width, this._renderTarget.height = r.height, 
  null !== i.outDepthID ? void 0 !== (t = this._textureMap[i.outDepthID]) ? (this._renderTarget.depthTexture = t, 
  this._renderTarget.depthTexture.width = r.width, this._renderTarget.depthTexture.height = r.height) : (i.target === RenderPass.TEXTURE_CUBE_MAP ? this._renderTarget.addDepthTexture(!0) : this._renderTarget.addDepthTexture(), 
  this._textureMap[i.outDepthID] = this._renderTarget.depthTexture) : this._renderTarget.depthTexture = null;
  for (let t = 0; t < i.outTextures.length; t++) {
   var s = i.outTextures[t], a = s.id, n = s.textureConfig;
   let e = this._textureMap[a];
   if (void 0 !== e) e.applyConfig(n), e.width = r.width, e.height = r.height, this._renderTarget.addDrawBuffer(e); else {
    let t;
    (t = i.target === RenderPass.TEXTURE_CUBE_MAP ? new CubeTexture({
     textures: void 0,
     wrapS: n.wrapS,
     wrapT: n.wrapT,
     wrapR: n.wrapR,
     minFilter: n.minFilter,
     magFilter: n.magFilter,
     internalFormat: n.internalFormat,
     format: n.format,
     type: n.type,
     size: Math.min(r.width, r.height)
    }) : new Texture(void 0, n.wrapS, n.wrapT, n.minFilter, n.magFilter, n.internalFormat, n.format, n.type, r.width, r.height)).clearFunction = n.clearFunction, 
    this._renderTarget.addDrawBuffer(t), this._textureMap[a] = t, e = t;
   }
   void 0 !== s.clearColorArray ? e.clearColorArray = s.clearColorArray : delete e.clearColorArray;
  }
 }
 render_begin(t = !1) {
  this._saved_vp ? console.error("RenderQueue.render_begin called without an intervening end.") : (this._saved_vp = this._renderer.getViewport(), 
  this.used_check = t, this.used_last = !0, this.used_fail_count = 0);
 }
 render_pass_idx(t) {
  this.render_pass(this._renderQueue[t], t);
 }
 render_pass(t, e) {
  t._isInitialized || (t._initialize(this._textureMap, this._forwardedAdditionalData), 
  t._isInitialized = !0);
  var i = t.viewport, r = t.preprocess(this._textureMap, this._forwardedAdditionalData);
  if (null !== r) {
   if (t.type === RenderPass.BASIC) {
    if (!(void 0 !== r.scene && r.scene instanceof Scene && void 0 !== r.camera && r.camera instanceof Camera)) return void console.error("Render pass " + e + " has invalid preprocess output!");
    if (t.target === RenderPass.SCREEN) this._renderer.updateViewport(i.width, i.height, i.xOffset, i.yOffset), 
    this._renderer.render(r.scene, r.camera); else if (t.target === RenderPass.TEXTURE) this._setupRenderTarget(t), 
    this._renderer.render(r.scene, r.camera, this._renderTarget); else {
     if (t.target !== RenderPass.TEXTURE_CUBE_MAP) return void console.error("Unknown render pass " + e + " target.");
     this._setupRenderTarget(t), this._renderer.render(r.scene, r.camera, this._renderTarget, !0, t.side);
    }
   } else {
    if (t.type === RenderPass.TEXTURE_MERGE) {
     if (!(void 0 !== r.material && r.material instanceof CustomShaderMaterial && void 0 !== r.textures && Array.isArray(r.textures))) return void console.error("Render pass " + e + " has invalid preprocess output!");
     r.material.clearMaps();
     for (let t = 0; t < r.textures.length; t++) r.material.addMap(r.textures[t]);
    } else {
     if (t.type !== RenderPass.POSTPROCESS) return void console.error("Render queue contains RenderPass of unsupported type!");
     if (!(void 0 !== r.material && r.material instanceof CustomShaderMaterial && void 0 !== r.textures && Array.isArray(r.textures))) return void console.error("Render pass " + e + " has invalid preprocess output!");
     r.material.clearMaps();
     for (let t = 0; t < r.textures.length; t++) r.material.addMap(r.textures[t]);
    }
    if (this._textureMergeQuad.material = r.material, t.target === RenderPass.SCREEN) this._renderer.updateViewport(i.width, i.height, i.xOffset, i.yOffset), 
    this._renderer.render(this._textureMergeScene, this._textureMergeCamera); else {
     if (t.target !== RenderPass.TEXTURE) return void console.error("Unknown render pass " + e + " target.");
     this._setupRenderTarget(t), this._renderer.render(this._textureMergeScene, this._textureMergeCamera, this._renderTarget);
    }
   }
   t.postprocess(this._textureMap, this._forwardedAdditionalData), this.used_check && (this._renderer.used ? this.used_last = !0 : (this.used_last = !1, 
   ++this.used_fail_count));
  }
 }
 render_end() {
  return this._renderer.updateViewport(this._saved_vp.width, this._saved_vp.height, this._saved_vp.xOffset, this._saved_vp.yOffset), 
  delete this._saved_vp, {
   textures: this._textureMap,
   additionalData: this._forwardedAdditionalData
  };
 }
 render() {
  this.render_begin();
  for (let t = 0; t < this._renderQueue.length; t++) this.render_pass(this._renderQueue[t], t);
  return this.render_end();
 }
 addTexture(t, e) {
  this._textureMap[t] = e;
 }
 setDataValue(t, e) {
  this._forwardedAdditionalData[t] = e;
 }
 setRenderQueue(e) {
  for (let t = 0; t < e.length; t++) if (!(e[t] instanceof RenderPass)) return void console.error("Given render queue contains invalid elements!");
  this._renderQueue = e;
 }
 takeScreenshot(t, e = 1, i = !1) {
  t = this._textureMap[t];
  this._renderer.takeScreenshot(t, e, i, this);
 }
 pickRGB(t, e, i) {
  t = this._textureMap[t];
  return this._renderer.pickRGB(t, e, i, this);
 }
 pickUINT(t, e, i) {
  t = this._textureMap[t];
  return this._renderer.pickUINT(t, e, i, this);
 }
 downloadTexture(t) {
  var e = this._textureMap[t];
  return this._renderer.downloadTexture(e, t);
 }
 downloadAllTextures() {
  for (var t = Object.keys(this._textureMap), e = 0; e < t.length; e++) this.downloadTexture(t[e]);
 }
 clearRenderQueue() {
  this._renderQueue = [];
 }
 pushRenderPass(t) {
  t instanceof RenderPass ? this._renderQueue.push(t) : console.error("Given argument is not a RenderPass!");
 }
 removeRenderPass(t) {
  t = this._renderQueue.indexOf(t);
  -1 < t && this._renderQueue.splice(t, 1);
 }
 addRenderPass(t, e) {
  this._renderQueue.splice(e, 0, t);
 }
 popRenderPass() {
  return this._renderQueue.pop();
 }
 storeRenderQueue(t) {
  this._storedRenderQueues[t] = this._renderQueue;
 }
 loadRenderQueue(t) {
  t = this._storedRenderQueues[t];
  void 0 === t ? console.error("Error: Could not find the requested queue.") : this._renderQueue = t;
 }
 pushRenderQueue(t) {
  if (t instanceof RenderQueue) {
   var e = t._renderQueue;
   for (let t = 0; t < e.length; t++) this.pushRenderPass(e[t]);
  } else console.error("Given argument is not a RenderQueue!");
 }
}

class RenderArray {
 constructor() {
  this._uuid = _Math.generateUUID(), this._renderArray = [], this._renderArrayLength = this._renderArray.length;
 }
 get uuid() {
  return this._uuid;
 }
 get renderArray() {
  return this._renderArray;
 }
 get length() {
  return this._renderArray.length;
 }
 push(t) {
  return this._renderArray.push(t);
 }
 pop() {
  return this._renderArray.pop();
 }
 add(t, e) {
  this.addlast(t);
 }
 addlast(t) {
  return this._renderArray.push(t);
 }
 remove(t, e) {
  this.removeLast(t);
 }
 removeLast() {
  return this._renderArray.pop();
 }
 clear() {
  this._renderArray = new Array();
 }
 get(t) {
  return this._renderArray[t];
 }
 sort(t) {
  this._renderArray.sort(t);
 }
}

class RenderArrayManager {
 constructor() {
  this._uuid = _Math.generateUUID(), this._renderArrays = new Map(), this._skyboxes = new RenderArray(), 
  this._opaqueObjects = new RenderArray(), this._transparentObjects = new RenderArray(), 
  this._lights = new RenderArray();
 }
 get uuid() {
  return this._uuid;
 }
 get renderArrays() {
  return this._renderArrays;
 }
 get skyboxes() {
  return this._skyboxes;
 }
 get opaqueObjects() {
  return this._opaqueObjects;
 }
 get transparentObjects() {
  return this._transparentObjects;
 }
 get lights() {
  return this._lights;
 }
 clearAll() {
  for (var [ t, e ] of this._renderArrays) e.clear();
  this._skyboxes.clear(), this._opaqueObjects.clear(), this._transparentObjects.clear(), 
  this._lights.clear();
 }
}

class MeshRenderer extends Renderer {
 static MODE = {
  COLOR: 0,
  SHADOW: 1,
  P_SHADOW: 2,
  GEOMETRY: 3,
  PICK: 4
 };
 constructor(t, e, i) {
  super(t, e, i), this._projScreenMatrix = new Matrix4(), this._sphere = new Sphere(), 
  this._frustum = new Frustum(), this._renderArrayManager = new RenderArrayManager(), 
  this._lightsCombined = {
   ambient: [ 0, 0, 0 ],
   directional: [],
   point: [],
   spot: []
  }, this._zVector = new Vector3(), this._gl.enable(this._gl.DEPTH_TEST), this._gl.frontFace(this._gl.CCW), 
  this._selectedRenderer = this._meshRender, this.notinit = !0, this._wasReset = !0, 
  this._pickEnabled = !1, this._pickSecondaryEnabled = !1, this._pickObject3D = !1, 
  this._pickCoordinateX = 0, this._pickCoordinateY = 0, this._pickedID = 0, this._pickedObject3D = null, 
  this._pickCallback = null, this._outlineEnabled = !1, this._outlineArray = null, 
  this.used = !1;
 }
 set selectedRenderer(t) {
  this._selectedRenderer = t;
 }
 set pickObject3D(t) {
  this._pickObject3D = t;
 }
 get pickedID() {
  return this._pickedID;
 }
 get pickedObject3D() {
  return this._pickedObject3D;
 }
 _meshRender(t, e) {
  !0 === t.autoUpdate && t.updateMatrixWorld(), this._projScreenMatrix.multiplyMatrices(e.projectionMatrix, e.matrixWorldInverse), 
  this._frustum.setFromMatrix(this._projScreenMatrix), this._renderArrayManager.clearAll(), 
  this._updateObjects(t, e), 0 < this._renderArrayManager.lights.length && this._setupLights(this._renderArrayManager.lights, e), 
  this._loadRequiredPrograms() ? (this.used || (2 <= this._logLevel && (console.log("-----------------POST------------------"), 
  console.log("REQUIRED: " + this._requiredPrograms + " length: " + this._requiredPrograms.size), 
  console.log(this._requiredPrograms), console.log("--------------------------------------"), 
  console.log("LOADING: " + this._loadingPrograms + " length: " + this._loadingPrograms.size), 
  console.log(this._loadingPrograms), console.log("--------------------------------------"), 
  console.log("COMPILED: " + this._compiledPrograms + " length: " + this._compiledPrograms.size), 
  console.log(this._compiledPrograms), console.log("--------------------------------------")), 
  this.used = !0), this._outlineEnabled ? (this._outlineEnabled = !1, this._renderOutline(this._outlineArray, e)) : this._pickEnabled ? (this._pickEnabled = !1, 
  this._renderPickingObjects(this._renderArrayManager.opaqueObjects, this._renderArrayManager.transparentObjects, e)) : this._pickSecondaryEnabled ? (this._pickSecondaryEnabled = !1, 
  this._pickedObject3D && this.pick_instance(this._pickedObject3D, e)) : (this._renderOpaqueObjects(this._renderArrayManager.opaqueObjects, e), 
  this._renderTransparentObjects(this._renderArrayManager.transparentObjects, e), 
  this._renderOpaqueObjects(this._renderArrayManager.skyboxes, e))) : (1 <= this._logLevel && console.warn("Required programs not loaded!"), 
  2 <= this._logLevel && (console.log("-----------------PRE-----------------"), 
  console.log("REQUIRED: " + this._requiredPrograms + " length: " + this._requiredPrograms.size), 
  console.log(this._requiredPrograms), console.log("--------------------------------------"), 
  console.log("LOADING: " + this._loadingPrograms + " length: " + this._loadingPrograms.size), 
  console.log(this._loadingPrograms), console.log("--------------------------------------"), 
  console.log("COMPILED: " + this._compiledPrograms + " length: " + this._compiledPrograms.size), 
  console.log(this._compiledPrograms), console.log("--------------------------------------")), 
  this.used = !1);
 }
 _renderPickingObjects(t, e, i) {
  this._gl.clearBufferuiv(this._gl.COLOR, 0, new Uint32Array([ 4294967295, 0, 0, 0 ])), 
  this._gl.clearBufferfi(this._gl.DEPTH_STENCIL, 0, 1, 0), this._pickObject3D && (this._pickLUA = []), 
  this._renderPickableObjects(t, i), this._renderPickableObjects(e, i);
  t = new Uint32Array(4);
  this._gl.readBuffer(this._gl.COLOR_ATTACHMENT0), this._gl.readPixels(this._pickCoordinateX, this._pickCoordinateY, 1, 1, this._gl.RGBA_INTEGER, this._gl.UNSIGNED_INT, t), 
  this._pickedID = 4294967295 != t[0] ? t[0] : null, this._pickObject3D ? (this._pickedObject3D = null !== this._pickedID ? this._pickLUA[this._pickedID] : null, 
  delete this._pickLUA, this._pickCallback && this._pickCallback(this._pickedObject3D)) : this._pickCallback && this._pickCallback(this._pickedID);
 }
 _renderOpaqueObjects(t, e) {
  0 < t.length && (t.sort(function(t, e) {
   return t.renderOrder - e.renderOrder;
  }), this._renderObjects(t, e));
 }
 _renderTransparentObjects(t, e) {
  0 < t.length && (t.sort(function(t, e) {
   var i = t.renderOrder - e.renderOrder;
   return 0 == i ? e._zVector.z - t._zVector.z : i;
  }), this._gl.enable(this._gl.BLEND), this._gl.blendEquation(this._gl.FUNC_ADD), 
  this._gl.blendFuncSeparate(this._gl.SRC_ALPHA, this._gl.ONE_MINUS_SRC_ALPHA, this._gl.ONE, this._gl.ONE_MINUS_SRC_ALPHA), 
  this._renderObjects(t, e), this._gl.disable(this._gl.BLEND));
 }
 requestProgram(t) {
  var e;
  return null === t || (e = t.programID, !!this._compiledPrograms.has(e)) || (this._loadingPrograms.has(e) && this._requiredPrograms.has(e) ? void 0 : (this._requiredPrograms.set(e, t), 
  !1));
 }
 _renderObjects(i, r) {
  for (let t = 0; t < i.length; t++) {
   var s = i.get(t), a = s.getRequiredPrograms(this);
   let e = !0;
   for (let t = 0; t < a.length; t++) e = e && this.requestProgram(a[t]);
   if (e) {
    let t;
    (t = this._renderMode === MeshRenderer.MODE.COLOR ? s.material : this._renderMode === MeshRenderer.MODE.SHADOW ? s._DSM : this._renderMode === MeshRenderer.MODE.P_SHADOW ? s._PSM : this._renderMode == MeshRenderer.MODE.GEOMETRY ? s.GBufferMaterial : this._renderMode == MeshRenderer.MODE.PICK ? s._PM : s.material).side = s.material.side, 
    t.isStatic = s.material.isStatic, t.instanced = s.material.instanced, t.normalFlat = s.material.normalFlat;
    var n = t.requiredProgram(this).programID;
    if (void 0 === this._compiledPrograms.get(n)) return void console.warn("NO PROGRAM LOADED");
    this._setupProgram(s, r, t), this._setup_material_settings(t), this._drawObject(s);
   }
  }
 }
 _renderPickableObjects(e, i) {
  for (let t = 0; t < e.length; t++) {
   var r, s = e.get(t);
   s.pickable && (this._pickObject3D && (s.UINT_ID = this._pickLUA.length, this._pickLUA.push(s)), 
   r = s.pickingMaterial, this._setupProgram(s, i, r), this._setup_material_side(r.side), 
   this._setup_material_depth(!0, r.depthFunc, !0), this._drawObject(s));
  }
 }
 _renderOutline(i, r) {
  for (let e = 0; e < i.length; e++) {
   var s = i[e], a = s.outlineMaterial || (s.material.normalFlat ? this._defaultOutlineMatFlat : this._defaultOutlineMat);
   this._setupProgram(s, r, a), this._setup_material_side(a.side), this._setup_material_depth(!0, a.depthFunc, !0);
   let t = 0;
   a.getUniform("u_OutlineGivenInstances") && (t = a.getAttribute("a_OutlineInstances").count()), 
   this._drawObject(s, t);
  }
 }
 _setupProgram(t, e, i) {
  var r = i.requiredProgram(this).programID, r = this._compiledPrograms.get(r);
  r.use(), this._setup_uniforms(r, t, e, i), this._setup_attributes(r, t, i);
 }
 _drawObject(t, e = 0) {
  "function" != typeof t.draw && console.warn("Object " + t.type + " has no draw function"), 
  t.draw(this._gl, this._glManager, e);
 }
 _setup_attributes(i, r, t) {
  var s, a = i.attributeSetter, n = Object.getOwnPropertyNames(a), o = t._attributes;
  for (let e = 0; e < n.length; e++) switch (n[e]) {
  case "VPos":
   var h = r.geometry.vertices;
   h ? a.VPos.set(h, h.itemSize, r.instanced, h.divisor) : console.error("[" + r.type + "]: vertices not found in geometry!");
   break;

  case "VNorm":
   h = r.geometry.normals;
   h ? a.VNorm.set(h, 3, r.instanced, h.divisor) : console.error("[" + r.type + "]: normals not found in geometry!");
   break;

  case "a_Tangent":
   var u = r.geometry.tangents;
   u ? a.a_Tangent.set(u, 3, r.instanced, u.divisor) : console.error("[" + r.type + "]: tangents not found in geometry!");
   break;

  case "a_Bitangent":
   u = r.geometry.bitangents;
   u ? a.a_Bitangent.set(u, 3, r.instanced, u.divisor) : console.error("[" + r.type + "]: bitangents not found in geometry!");
   break;

  case "VColor":
   var l = r.geometry.vertColor;
   l ? a.VColor.set(l, 4, r.instanced, l.divisor) : console.error("[" + r.type + "]: vertColor not found in geometry!");
   break;

  case "uv":
   l = r.geometry.uv;
   l ? a.uv.set(l, 2, r.instanced, l.divisor) : console.error("[" + r.type + "]: uv not found in geometry!");
   break;

  case "MMat":
   var _ = r.geometry.MMat;
   _ ? a.MMat.set(_, 16, r.instanced, _.divisor) : console.error("[" + r.type + "]: MMat not found in geometry!");
   break;

  case "a_Translation":
   _ = r.geometry.translation;
   _ ? a.a_Translation.set(_, 4, r.instanced, _.divisor) : console.error("[" + r.type + "]: Translation not found in geometry!");
   break;

  case "gl_InstanceID":
  case "gl_VertexID":
   break;

  default:
   let t = !1;
   void 0 !== o && void 0 !== (s = o[n[e]]) && (t = !0, a[n[e]].set(s, s.itemSize, r.instanced, s.divisor)), 
   t || (console.error("----------------------------------------"), console.error("Attribute (" + n[e] + ") not set!"), 
   console.error(r), console.error(i), console.error(a), console.error("----------------------------------------"));
  }
 }
 _setup_uniforms(t, i, e, r, s = void 0) {
  var a, n = t.uniformSetter, o = (n.__validation.reset(), void 0 !== n.PMat && n.PMat.set(e.projectionMatrix.elements), 
  void 0 !== n.u_PMatInv && n.u_PMatInv.set(e.projectionMatrixInverse.elements), 
  void 0 !== n.MVMat && n.MVMat.set(i.modelViewMatrix.elements), void 0 !== n.NMat && n.NMat.set(i.normalMatrix.elements), 
  void 0 !== n.u_MMat && n.u_MMat.set(i.matrixWorld.elements), void 0 !== n.VMat && n.VMat.set(e.matrixWorldInverse.elements), 
  void 0 !== n.MVPMat && (i.modelViewProjectionMatrix.multiplyMatrices(e.projectionMatrix, i.modelViewMatrix), 
  n.MVPMat.set(i.modelViewProjectionMatrix.elements)), void 0 !== n.cameraPosition && (a = new Vector3().setFromMatrixPosition(e.matrixWorld), 
  n.cameraPosition.set(a.toArray())), void 0 !== n.lightPosition_worldspace && (a = new Vector3().setFromMatrixPosition(e.matrixWorld), 
  n.lightPosition_worldspace.set(a.toArray())), void 0 !== s && void 0 !== n.globalClippingPlanes && n.globalClippingPlanes.set(s.elements), 
  void 0 !== n.u_RGB_ID && n.u_RGB_ID.set(i.RGB_ID.toArray()), void 0 !== n.u_UINT_ID && n.u_UINT_ID.set(i.UINT_ID >>> 0), 
  void 0 !== n.aspect && n.aspect.set(this._viewport.width / this._viewport.height), 
  void 0 !== n.viewport && n.viewport.set([ this._viewport.width, this._viewport.height ]), 
  void 0 !== n.time && n.time.set(new Date().getMilliseconds()), void 0 !== n.u_clearColor && n.u_clearColor.set(this.clearColor.toArray()), 
  this._setup_light_uniforms(n), this._setup_material_uniforms(r, n, i), n.__validation.validate());
  if (0 < o.length) {
   let e = o[0];
   for (let t = 1; t < o.length; t++) e += ", " + o[t];
   console.error("----------------------------------------"), console.error("Uniforms (" + e + ") not set!"), 
   console.error(i), console.error(t), console.error(n), console.error("----------------------------------------");
  }
 }
 _setup_material_uniforms(e, i, t) {
  var r, s, a = e._uniforms;
  for (r in a) a.hasOwnProperty(r) && void 0 !== i[r] && ((s = a[r]) instanceof Function ? i[r].set(s()) : i[r].set(s));
  void 0 !== i["material.emissive"] && i["material.emissive"].set(e.emissive.toArray()), 
  void 0 !== i["material.diffuse"] && i["material.diffuse"].set(e.color.toArray()), 
  void 0 !== i["material.specular"] && i["material.specular"].set(e.specular.toArray()), 
  void 0 !== i["material.shininess"] && i["material.shininess"].set(e.shininess), 
  void 0 !== i["material.heightScale"] && i["material.heightScale"].set(e.heightScale), 
  void 0 !== i["material.blinn"] && i["material.blinn"].set(e.blinn), void 0 !== i["material.receiveShadows"] && i["material.receiveShadows"].set(e.receiveShadows);
  var n = e.diffuseMap, o = (n && void 0 !== i[o = "material.diffuseMap"] && i[o].set(this._glManager.getGLTexture(n), 0), 
  e.specularMap), n = (o && void 0 !== i[n = "material.specularMap"] && i[n].set(this._glManager.getGLTexture(o), 1), 
  e.normalMap), o = (n && void 0 !== i[o = "material.normalMap"] && i[o].set(this._glManager.getGLTexture(n), 2), 
  e.heightMap), h = (o && void 0 !== i[n = "material.heightMap"] && i[n].set(this._glManager.getGLTexture(o), 3), 
  e.instanceData);
  for (let t = 0; t < h.length; t++) {
   var u = "material.instanceData" + t;
   void 0 !== i[u] && i[u].set(this._glManager.getGLTexture(h[t]), 10 + t);
  }
  var l = e.maps;
  for (let t = 0; t < l.length; t++) {
   var _ = "material.texture" + t;
   void 0 !== i[_] && i[_].set(this._glManager.getGLTexture(l[t]), 15 + t);
  }
  var c, d = e.cubemaps;
  for (let t = 0; t < d.length; t++) {
   var m = "material.cubeTexture" + t;
   void 0 !== i[m] && i[m].set(this._glManager.getGLCubeTexture(d[t]), 20 + t);
  }
  if (!0 === e.usePoints && void 0 !== i.pointSize && i.pointSize.set(e.pointSize), 
  void 0 !== i.lineWidth && i.lineWidth.set(e.lineWidth), !0 === e.useClippingPlanes) for (let t = 0; t < e.clippingPlanes.length; t++) void 0 !== i[(c = "clippingPlanes[" + t + "]") + ".normal"] && i[c + ".normal"].set(e.clippingPlanes[t].normal.toArray()), 
  void 0 !== i[c + ".constant"] && i[c + ".constant"].set(e.clippingPlanes[t].constant);
  !0 === e.transparent ? (void 0 !== i.alpha && i.alpha.set(e.opacity), void 0 !== i["material.alpha"] && i["material.alpha"].set(e.opacity)) : (void 0 !== i.alpha && i.alpha.set(1), 
  void 0 !== i["material.alpha"] && i["material.alpha"].set(1));
 }
 _setup_material_settings(t) {
  this._setup_material_side(t.side), this._setup_material_depth(t.depthTest, t.depthFunc, t.depthWrite);
 }
 _setup_material_side(t) {
  t === FRONT_AND_BACK_SIDE ? this._gl.disable(this._gl.CULL_FACE) : t === FRONT_SIDE ? (this._gl.enable(this._gl.CULL_FACE), 
  this._gl.cullFace(this._gl.BACK)) : t === BACK_SIDE && (this._gl.enable(this._gl.CULL_FACE), 
  this._gl.cullFace(this._gl.FRONT));
 }
 _setup_material_depth(t, e, i) {
  if (t) switch (this._gl.enable(this._gl.DEPTH_TEST), e) {
  case FUNC_LEQUAL:
   this._gl.depthFunc(this._gl.LEQUAL);
   break;

  case FUNC_LESS:
   this._gl.depthFunc(this._gl.LESS);
   break;

  case FUNC_GEQUAL:
   this._gl.depthFunc(this._gl.GEQUAL);
   break;

  case FUNC_GREATER:
   this._gl.depthFunc(this._gl.GREATER);
   break;

  case FUNC_EQUAL:
   this._gl.depthFunc(this._gl.EQUAL);
   break;

  case FUNC_NOTEQUAL:
   this._gl.depthFunc(this._gl.NOTEQUAL);
   break;

  case FUNC_NEVER:
   this._gl.depthFunc(this._gl.NEVER);
   break;

  case FUNC_ALWAYS:
   this._gl.depthFunc(this._gl.ALWAYS);
  } else this._gl.disable(this._gl.DEPTH_TEST);
  this._gl.depthMask(i);
 }
 _setup_light_uniforms(e) {
  void 0 !== e.ambient && e.ambient.set(this._lightsCombined.ambient);
  for (let t = 0; t < this._lightsCombined.directional.length; t++) {
   var i, r = "dLights[" + t + "]", s = this._lightsCombined.directional[t], a = (e[r + ".position"] && e[r + ".position"].set(s.direction.toArray()), 
   e[r + ".direction"] && e[r + ".direction"].set(s.direction.toArray()), e[r + ".color"] && e[r + ".color"].set(s.color.toArray()), 
   void 0 !== e[r + ".VPMat"] && e[r + ".VPMat"].set(s.VPMat.elements), s.shadowmap);
   a && void 0 !== e[i = r + ".shadowmap"] && e[i].set(this._glManager.getGLTexture(a), 8 + t), 
   e[r + ".castShadows"] && e[r + ".castShadows"].set(s.castShadows), e[r + ".hardShadows"] && e[r + ".hardShadows"].set(s.hardShadows), 
   e[r + ".minBias"] && e[r + ".minBias"].set(s.minBias), e[r + ".maxBias"] && e[r + ".maxBias"].set(s.maxBias);
  }
  for (let t = 0; t < this._lightsCombined.point.length; t++) {
   var n, o = "pLights[" + t + "]", h = this._lightsCombined.point[t], u = (e[o + ".position"] && e[o + ".position"].set(h.position.toArray()), 
   e[o + ".position_worldspace"] && e[o + ".position_worldspace"].set(h.position_worldspace.toArray()), 
   e[o + ".position_screenspace"] && e[o + ".position_screenspace"].set(h.position_screenspace.toArray()), 
   e[o + ".color"] && e[o + ".color"].set(h.color.toArray()), e[o + ".distance"] && e[o + ".distance"].set(h.distance), 
   e[o + ".decay"] && e[o + ".decay"].set(h.decay), void 0 !== e[o + ".VPMat"] && e[o + ".VPMat"].set(h.VPMat.elements), 
   h.shadowmap);
   u && void 0 !== e[n = o + ".shadowmap"] && e[n].set(this._glManager.getGLCubeTexture(u), 10 + t), 
   e[o + ".castShadows"] && e[o + ".castShadows"].set(h.castShadows), e[o + ".hardShadows"] && e[o + ".hardShadows"].set(h.hardShadows), 
   e[o + ".minBias"] && e[o + ".minBias"].set(h.minBias), e[o + ".maxBias"] && e[o + ".maxBias"].set(h.maxBias), 
   e[o + ".shadowFar"] && e[o + ".shadowFar"].set(h.shadowFar), e[o + ".constant"] && e[o + ".constant"].set(h.constant), 
   e[o + ".linear"] && e[o + ".linear"].set(h.linear), e[o + ".quadratic"] && e[o + ".quadratic"].set(h.quadratic);
  }
  for (let t = 0; t < this._lightsCombined.spot.length; t++) {
   var l, _ = "sLights[" + t + "]", c = this._lightsCombined.spot[t], d = (e[_ + ".position"] && e[_ + ".position"].set(c.position.toArray()), 
   e[_ + ".position_screenspace"] && e[_ + ".position_screenspace"].set(c.position_screenspace.toArray()), 
   e[_ + ".color"] && e[_ + ".color"].set(c.color.toArray()), e[_ + ".distance"] && e[_ + ".distance"].set(c.distance), 
   e[_ + ".decay"] && e[_ + ".decay"].set(c.decay), e[_ + ".cutoff"] && e[_ + ".cutoff"].set(c.cutoff), 
   e[_ + ".outerCutoff"] && e[_ + ".outerCutoff"].set(c.outerCutoff), e[_ + ".direction"] && e[_ + ".direction"].set(c.direction.toArray()), 
   e[_ + ".direction_screenspace"] && e[_ + ".direction_screenspace"].set(c.direction_screenspace.toArray()), 
   void 0 !== e[_ + ".VPMat"] && e[_ + ".VPMat"].set(c.VPMat.elements), c.shadowmap);
   d && void 0 !== e[l = _ + ".shadowmap"] && e[l].set(this._glManager.getGLTexture(d), 12 + t), 
   e[_ + ".castShadows"] && e[_ + ".castShadows"].set(c.castShadows), e[_ + ".hardShadows"] && e[_ + ".hardShadows"].set(c.hardShadows), 
   e[_ + ".minBias"] && e[_ + ".minBias"].set(c.minBias), e[_ + ".maxBias"] && e[_ + ".maxBias"].set(c.maxBias), 
   e[_ + ".constant"] && e[_ + ".constant"].set(c.constant), e[_ + ".linear"] && e[_ + ".linear"].set(c.linear), 
   e[_ + ".quadratic"] && e[_ + ".quadratic"].set(c.quadratic);
  }
 }
 _updateObjects(e, i) {
  if (e.visible && (this._objectInFrustum(e) || this._screenshotInProgress)) {
   e.fillRenderArray(this._renderArrayManager), e.project(this._projScreenMatrix);
   var r = e.getRequiredPrograms(this);
   for (let t = 0; t < r.length; t++) this._fillRequiredPrograms(r[t]);
   e.update(this._glManager, i);
   for (let t = 0; t < e.children.length; t++) this._updateObjects(e.children[t], i);
  }
 }
 _fillRequiredPrograms(t) {
  null === t || this._requiredPrograms.has(t.programID) || this._requiredPrograms.set(t.programID, t);
 }
 _setupLights(e, i) {
  this._lightsCombined.ambient = [ 0, 0, 0 ], this._lightsCombined.directional.length = 0, 
  this._lightsCombined.point.length = 0;
  let r = this._lightsCombined.spot.length = 0, s = 0, a = 0;
  for (let t = 0; t < e.length; t++) {
   var n, o, h, u, l = (u = e.get(t)).color, _ = u.intensity;
   u instanceof AmbientLight ? (r += l.r * _, s += l.g * _, a += l.b * _, this._lightsCombined.ambient[0] += u.color.r * u.intensity, 
   this._lightsCombined.ambient[1] += u.color.g * u.intensity, this._lightsCombined.ambient[2] += u.color.b * u.intensity) : u instanceof DirectionalLight ? ((l = {
    color: new Color(),
    direction: new Vector4(),
    ref: u,
    VPMat: new Matrix4(),
    shadowmap: null,
    castShadows: void 0,
    hardShadows: !0,
    minBias: .005,
    maxBias: .05
   }).color.copy(u.color).multiplyScalar(u.intensity), l.direction.set(u.direction.x, u.direction.y, u.direction.z, 0), 
   l.direction.applyMatrix4(u.matrixWorld), l.direction.applyMatrix4(i.matrixWorldInverse), 
   _ = new Matrix4().getInverse(u.cameraGroup.children[0].matrixWorld), n = u.cameraGroup.children[0].projectionMatrix, 
   n = new Matrix4().multiplyMatrices(n, _), l.VPMat = n, l.shadowmap = u.shadowmap, 
   l.castShadows = u.castShadows, l.hardShadows = u.hardShadows, l.minBias = u.minBias, 
   l.maxBias = u.maxBias, this._lightsCombined.directional.push(l)) : u instanceof PointLight ? ((_ = {
    color: new Color(),
    position: new Vector3(),
    position_worldspace: new Vector3(),
    position_screenspace: new Vector3(),
    distance: u.distance,
    decay: u.decay,
    ref: u,
    VPMat: new Matrix4(),
    shadowmap: null,
    castShadows: void 0,
    hardShadows: !0,
    minBias: .005,
    maxBias: .05,
    shadowFar: 128,
    constant: u.constant,
    linear: u.linear,
    quadratic: u.quadratic
   }).position_worldspace.setFromMatrixPosition(u.matrixWorld), _.position.setFromMatrixPosition(u.matrixWorld), 
   _.position.applyMatrix4(i.matrixWorldInverse), _.position_screenspace.setFromMatrixPosition(u.matrixWorld), 
   _.position_screenspace.applyMatrix4(i.matrixWorldInverse), n = _.position_screenspace.z, 
   _.position_screenspace.applyMatrix4(i.projectionMatrix), 0 < n && _.position_screenspace.multiplyScalar(-1), 
   _.position_screenspace.multiplyScalar(.5), _.position_screenspace.addScalar(.5), 
   l = new Matrix4().getInverse(u.cameraGroup.children[0].matrixWorld), o = u.cameraGroup.children[0].projectionMatrix, 
   o = new Matrix4().multiplyMatrices(o, l), _.VPMat = o, _.shadowmap = u.shadowmap, 
   _.castShadows = u.castShadows, _.hardShadows = u.hardShadows, _.minBias = u.minBias, 
   _.maxBias = u.maxBias, _.shadowFar = u.shadowFar, _.color.copy(u.color).multiplyScalar(u.intensity), 
   this._lightsCombined.point.push(_)) : u instanceof SpotLight && ((l = {
    color: new Color(),
    position: new Vector3(),
    position_screenspace: new Vector3(),
    distance: u.distance,
    decay: u.decay,
    cutoff: Math.cos(u.cutoff),
    outerCutoff: Math.cos(u.outerCutoff),
    direction: new Vector4(),
    direction_screenspace: new Vector4(),
    ref: u,
    VPMat: new Matrix4(),
    shadowmap: null,
    castShadows: void 0,
    hardShadows: !0,
    minBias: .005,
    maxBias: .05,
    constant: u.constant,
    linear: u.linear,
    quadratic: u.quadratic
   }).position.setFromMatrixPosition(u.matrixWorld), l.position.applyMatrix4(i.matrixWorldInverse), 
   l.position_screenspace.setFromMatrixPosition(u.matrixWorld), l.position_screenspace.applyMatrix4(i.matrixWorldInverse), 
   l.position_screenspace.z, l.position_screenspace.applyMatrix4(i.projectionMatrix), 
   l.position_screenspace.multiplyScalar(.5), l.position_screenspace.addScalar(.5), 
   l.color.copy(u.color).multiplyScalar(u.intensity), l.direction.set(u.direction.x, u.direction.y, u.direction.z, 0), 
   l.direction.applyMatrix4(u.matrixWorld), l.direction.applyMatrix4(i.matrixWorldInverse), 
   l.direction_screenspace.set(u.direction.x, u.direction.y, u.direction.z, 0), 
   l.direction_screenspace.applyMatrix4(u.matrixWorld), l.direction_screenspace.applyMatrix4(i.matrixWorldInverse), 
   o = l.direction_screenspace.z, l.direction_screenspace.applyMatrix4(i.projectionMatrix), 
   l.direction_screenspace.multiplyScalar(1 / l.direction_screenspace.w), 0 < o && l.direction_screenspace.multiplyScalar(-1), 
   _ = new Matrix4().getInverse(u.cameraGroup.children[0].matrixWorld), h = u.cameraGroup.children[0].projectionMatrix, 
   h = new Matrix4().multiplyMatrices(h, _), l.VPMat = h, l.shadowmap = u.shadowmap, 
   l.castShadows = u.castShadows, l.hardShadows = u.hardShadows, l.minBias = u.minBias, 
   l.maxBias = u.maxBias, this._lightsCombined.spot.push(l));
  }
 }
 _objectInFrustum(t) {
  var e;
  return !t.frustumCulled || (t._UPDATE_BOUNDS && (e = t.boundingSphere, this._sphere.copy(e).applyMatrix4(t.matrixWorld), 
  t._UPDATE_BOUNDS = !1), this._frustum.intersectsSphere(this._sphere));
 }
 pick_setup(t, e, i = null) {
  this._pickEnabled = !0, this._pickCoordinateX = t, this._pickCoordinateY = e, 
  this._pickCallback = i;
 }
 pick_instance(t, e) {
  this._gl.clearBufferuiv(this._gl.COLOR, 0, new Uint32Array([ 4294967295, 0, 0, 0 ])), 
  this._gl.clearBufferfi(this._gl.DEPTH_STENCIL, 0, 1, 0), t.pickingMaterial.setUniform("u_PickInstance", !0), 
  this._setupProgram(t, e, t.pickingMaterial), this._setup_material_side(t.material.side), 
  this._setup_material_depth(!0, t.material.depthFunc, !0), this._drawObject(t), 
  t.pickingMaterial.setUniform("u_PickInstance", !1);
  e = new Uint32Array(4);
  return this._gl.readBuffer(this._gl.COLOR_ATTACHMENT0), this._gl.readPixels(this._pickCoordinateX, this._pickCoordinateY, 1, 1, this._gl.RGBA_INTEGER, this._gl.UNSIGNED_INT, e), 
  this._pickedID = 4294967295 != e[0] ? e[0] : null, this._pickedID;
 }
}

class FX extends RenderQueue {
 constructor(t, e, i) {
  super(t), this._inputs = e, this._outputs = i;
 }
 static iterateSceneR(e, i) {
  if (null != e) {
   if (0 < e.children.length) for (let t = 0; t < e.children.length; t++) FX.iterateSceneR(e.children[t], i);
   i(e);
  }
 }
 get inputs() {
  return this._inputs;
 }
 get outputs() {
  return this._outputs;
 }
}

FX.input = class {
 constructor(t) {
  this._name = t;
 }
 get name() {
  return this._name;
 }
 connect() {}
}, FX.output = class {
 constructor(t) {
  this._name = t;
 }
 get name() {
  return this._name;
 }
 connect() {}
}, document.body.clientWidth, document.body.clientHeight, document.body.clientWidth, 
document.body.clientHeight, document.body.clientWidth, document.body.clientHeight, 
document.body.clientWidth, document.body.clientHeight, document.body.clientWidth, 
document.body.clientHeight, document.body.clientWidth, document.body.clientHeight, 
document.body.clientWidth, document.body.clientHeight;

const predef_width = document.body.clientWidth, predef_height = document.body.clientHeight;

class PickerFX extends FX {
 static PICK_MODE = {
  RGB: PickingShaderMaterial.PICK_MODE.RGB,
  UINT: PickingShaderMaterial.PICK_MODE.UINT
 };
 constructor(t, i = {}, e = {}, r = {}) {
  super(t, i, r), this.inputs.scene = this.inputs.scene || void 0, this.inputs.camera = this.inputs.camera || void 0, 
  this.outputs.color = this.outputs.color || new FX.output("color_picker"), this._pickMode = null;
  const s = new Map(), a = new Map(), n = new Map();
  this._renderPass_Picker = new RenderPass(RenderPass.BASIC, (t, e) => {
   FX.iterateSceneR(i.scene, t => {
    t instanceof Mesh && (s.set(t._uuid, t.material), a.set(t._uuid, t.pickingMaterial), 
    n.set(t._uuid, t.visible));
   });
  }, (t, e) => (FX.iterateSceneR(i.scene, t => {
   t instanceof Mesh && (t.pickable ? (s.get(t._uuid) && a.get(t._uuid) || (s.set(t._uuid, t.material), 
   a.set(t._uuid, t.pickingMaterial), n.set(t._uuid, t.visible)), t.material = a.get(t._uuid), 
   t.material.pickMode = this._pickMode) : t.visible = !1);
  }), {
   scene: i.scene,
   camera: i.camera
  }), (t, e) => {
   FX.iterateSceneR(i.scene, t => {
    t instanceof Mesh && (t.pickable ? (s.get(t._uuid) && a.get(t._uuid) || (s.set(t._uuid, t.material), 
    a.set(t._uuid, t.pickingMaterial), n.set(t._uuid, t.visible)), t.material = s.get(t._uuid)) : t.visible = n.get(t._uuid));
   });
  }, RenderPass.TEXTURE, {
   width: predef_width,
   height: predef_height
  }, "depth_color_picker", [ {
   id: r.color.name,
   textureConfig: RenderPass.DEFAULT_RGBA_TEXTURE_CONFIG
  } ]), this.pushRenderPass(this._renderPass_Picker), this.pickMode = e.pickMode || PickerFX.PICK_MODE.RGB;
 }
 get pickMode() {
  return this._pickMode;
 }
 set pickMode(t) {
  (this._pickMode = t) === PickerFX.PICK_MODE.RGB ? this._renderPass_Picker.outTextures = [ {
   id: this.outputs.color.name,
   textureConfig: RenderPass.DEFAULT_RGBA_TEXTURE_CONFIG
  } ] : t === PickerFX.PICK_MODE.UINT ? this._renderPass_Picker.outTextures = [ {
   id: this.outputs.color.name,
   textureConfig: RenderPass.DEFAULT_R32UI_TEXTURE_CONFIG
  } ] : console.error("Unknown pick mode: [" + t + "].");
 }
}

document.body.clientWidth, document.body.clientHeight, document.body.clientWidth, 
document.body.clientHeight, document.body.clientWidth, document.body.clientHeight;

class Point extends Mesh {
 constructor(t = {}) {
  super(t.geometry || new Geometry({
   vertices: new Float32Attribute([ 0, 0, 0 ], 3)
  }), t.material || new PointBasicMaterial(), new PickingShaderMaterial("POINTS", {
   pointSize: 1
  })), this.type = "Point", this.renderingPrimitive = POINTS;
 }
 set points(t) {
  this.geometry.vertices = Float32Attribute(t, 3);
 }
 get points() {
  return this.geometry.vertices;
 }
 static fromJson(t, e, i) {
  e = new Point(e, i);
  return super.fromJson(t, void 0, void 0, e);
 }
}

class GLManager {
 static sCheckFrameBuffer = !0;
 static sProgramCaching = null;
 constructor(t, e, i) {
  this._gl = null;
  for (var r = (this._glVersion = e) == WEBGL1 ? [ "webgl", "experimental-webgl" ] : [ "webgl2", "experimental-webgl2" ], s = 0; s < r.length; s++) {
   try {
    this._gl = t.canvasDOM.getContext(r[s], i);
   } catch (t) {
    console.error(t);
   }
   if (this._gl) break;
  }
  if (!this._gl) throw "ERROR: Failed to retrieve GL Context.";
  this._gl.getExtension("EXT_color_buffer_float"), this._FIRST_COLOR_ATTACHMENT = this._gl.COLOR_ATTACHMENT0, 
  this._LAST_COLOR_ATTACHMENT = this._gl.COLOR_ATTACHMENT15, this._fboManager = new GLFrameBufferManager(this._gl), 
  this._textureManager = new GLTextureManager(this._gl), this._attributeManager = new GLAttributeManager(this._gl), 
  this.autoClear = !0, this._clearColor = new Vector4(0, 0, 0, 0), this._clearDepth = null, 
  this._clearStencil = null, this.setClearColor(0, 0, 0, 0), this.setClearDepth(1), 
  this.setClearStencil(0);
 }
 updateBufferAttribute(t, e) {
  e ? this._attributeManager.updateAttribute(t, this._gl.ELEMENT_ARRAY_BUFFER) : this._attributeManager.updateAttribute(t, this._gl.ARRAY_BUFFER);
 }
 initRenderTarget(e) {
  let i;
  var r, s = [];
  this._fboManager.bindFramebuffer(e), null !== e.depthTexture ? (i = this._textureManager.getGLTexture(e.depthTexture, !0), 
  this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.DEPTH_ATTACHMENT, this._gl.TEXTURE_2D, i, 0), 
  this._gl.bindTexture(this._gl.TEXTURE_2D, null)) : this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.DEPTH_ATTACHMENT, this._gl.TEXTURE_2D, null, 0), 
  r = e.sizeDrawBuffers();
  for (let t = 0; t < r; t++) i = this._textureManager.getGLTexture(e._drawBuffers[t], !0), 
  this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._FIRST_COLOR_ATTACHMENT + t, this._gl.TEXTURE_2D, i, 0), 
  s.push(this._FIRST_COLOR_ATTACHMENT + t);
  if (this._gl.bindTexture(this._gl.TEXTURE_2D, null), null !== e.__fboLength && e.__fboLength > r) for (let t = r; t < e.__fboLength; t++) this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._FIRST_COLOR_ATTACHMENT + t, this._gl.TEXTURE_2D, null, 0);
  if (this._gl.drawBuffers(s), e.__fboLength = r, GLManager.sCheckFrameBuffer && this._gl.checkFramebufferStatus(this._gl.FRAMEBUFFER) !== this._gl.FRAMEBUFFER_COMPLETE) switch (console.error("Render target: framebuffer not complete!"), 
  this._gl.checkFramebufferStatus(this._gl.FRAMEBUFFER)) {
  case this._gl.FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
   console.error("FRAMEBUFFER_INCOMPLETE_ATTACHMENT: The attachment types are mismatched or not all framebuffer attachment points are framebuffer attachment complete.");
   break;

  case this._gl.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
   console.error("FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: There is no attachment.");
   break;

  case this._gl.FRAMEBUFFER_INCOMPLETE_DIMENSIONS:
   console.error("FRAMEBUFFER_INCOMPLETE_DIMENSIONS: Problem with the texture dimensions.");
   break;

  case this._gl.FRAMEBUFFER_UNSUPPORTED:
   console.error("FRAMEBUFFER_UNSUPPORTED: The format of the attachment is not supported or if depth and stencil attachments are not the same renderbuffer.");
   break;

  case this._gl.FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
   console.error("FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: The values of gl.RENDERBUFFER_SAMPLES are different among attached renderbuffers, or are non-zero if the attached images are a mix of renderbuffers and textures.");
   break;

  default:
   console.error("Unknown error! Abandon hope all ye who enter here.");
  }
  this.clearSeparate(e);
 }
 initRenderTargetCube(e, i) {
  let r;
  var s, a = [];
  this._fboManager.bindFramebuffer(e), null !== e.depthTexture ? (r = this._textureManager.getGLCubeTexture(e.depthTexture, !0), 
  this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.DEPTH_ATTACHMENT, this._gl.TEXTURE_CUBE_MAP_POSITIVE_X + i, r, 0), 
  this._gl.bindTexture(this._gl.TEXTURE_CUBE_MAP, null)) : this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.DEPTH_ATTACHMENT, this._gl.TEXTURE_CUBE_MAP_POSITIVE_X + i, null, 0), 
  s = e.sizeDrawBuffers();
  for (let t = 0; t < s; t++) r = this._textureManager.getGLCubeTexture(e._drawBuffers[t], !0), 
  this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._FIRST_COLOR_ATTACHMENT + t, this._gl.TEXTURE_CUBE_MAP_POSITIVE_X + i, r, 0), 
  a.push(this._FIRST_COLOR_ATTACHMENT + t);
  if (this._gl.bindTexture(this._gl.TEXTURE_CUBE_MAP, null), null !== e.__fboLength && e.__fboLength > s) for (let t = s; t < e.__fboLength; t++) this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._FIRST_COLOR_ATTACHMENT + t, this._gl.TEXTURE_CUBE_MAP_POSITIVE_X + i, null, 0);
  if (this._gl.drawBuffers(a), e.__fboLength = s, GLManager.sCheckFrameBuffer && this._gl.checkFramebufferStatus(this._gl.FRAMEBUFFER) !== this._gl.FRAMEBUFFER_COMPLETE) switch (console.error("Render target: framebuffer not complete!"), 
  this._gl.checkFramebufferStatus(this._gl.FRAMEBUFFER)) {
  case this._gl.FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
   console.error("FRAMEBUFFER_INCOMPLETE_ATTACHMENT: The attachment types are mismatched or not all framebuffer attachment points are framebuffer attachment complete.");
   break;

  case this._gl.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
   console.error("FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: There is no attachment.");
   break;

  case this._gl.FRAMEBUFFER_INCOMPLETE_DIMENSIONS:
   console.error("FRAMEBUFFER_INCOMPLETE_DIMENSIONS: Problem with the texture dimensions.");
   break;

  case this._gl.FRAMEBUFFER_UNSUPPORTED:
   console.error("FRAMEBUFFER_UNSUPPORTED: The format of the attachment is not supported or if depth and stencil attachments are not the same renderbuffer.");
   break;

  case this._gl.FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
   console.error("FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: The values of gl.RENDERBUFFER_SAMPLES are different among attached renderbuffers, or are non-zero if the attached images are a mix of renderbuffers and textures.");
   break;

  default:
   console.error("Unknown error! Abandon hope all ye who enter here.");
  }
  this.clearSeparate(e);
 }
 clearSeparate(e) {
  var r = e.sizeDrawBuffers(), s = (this._gl.depthMask(!0), this._gl.clearBufferfv(this._gl.DEPTH, 0, new Float32Array([ 1, 1, 1, 1 ])), 
  this._clearColor.toArray());
  for (let t = 0; t < r; t++) {
   var a, n = e._drawBuffers[t];
   null !== n.clearColorArray && (1 === n.clearFunction ? (a = n.clearColorArray || new Uint32Array(s), 
   this._gl.clearBufferuiv(this._gl.COLOR, t, a)) : 2 === n.clearFunction ? (a = n.clearColorArray || new Int32Array(s), 
   this._gl.clearBufferiv(this._gl.COLOR, t, a)) : 3 === n.clearFunction ? (n = n.clearColorArray || new Float32Array(s), 
   this._gl.clearBufferfv(this._gl.COLOR, t, n)) : console.error("Unsupported value for clearFunction", e._drawBuffers[i].clearFunction));
  }
 }
 cleanupRenderTarget() {
  this._fboManager.unbindFramebuffer();
 }
 getGLTexture(t) {
  return this._textureManager.getGLTexture(t);
 }
 getGLCubeTexture(t) {
  return this._textureManager.getGLCubeTexture(t);
 }
 downloadTexture(t, e) {
  var i = this._textureManager.getGLTexture(t), r = this._gl.createFramebuffer(), r = (this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, r), 
  this._gl.framebufferTexture2D(this._gl.FRAMEBUFFER, this._gl.COLOR_ATTACHMENT0, this._gl.TEXTURE_2D, i, 0), 
  document.createElement("canvas")), i = (r.width = t._width, r.height = t._height, 
  r.getContext("2d"));
  if (22 == t._type) {
   var s = new Float32Array(t._width * t._height * 4), a = (this._gl.readPixels(0, 0, t._width, t._height, this._gl.RGBA, this._gl.FLOAT, s), 
   "PF\n" + t._width + " " + t._height + "\n1.0\n"), n = new ArrayBuffer(a.length + t._width * t._height * 3 * 4), o = new DataView(n);
   for (let t = 0; t < a.length; t++) o.setUint8(t, a.charCodeAt(t));
   for (var h = 0; h < t._width * t._height; h++) o.setFloat32(a.length + 4 * (3 * h + 0), s[4 * h + 0]), 
   o.setFloat32(a.length + 4 * (3 * h + 1), s[4 * h + 1]), o.setFloat32(a.length + 4 * (3 * h + 2), s[4 * h + 2]);
   n = Array.prototype.map.call(new Uint8Array(n), function(t) {
    return String.fromCharCode(t);
   }).join("");
   console.log(n), (u = document.createElement("a")).download = e + ".pfm", u.href = "data:application/octet-stream;base64," + btoa(n), 
   u.click();
  } else {
   n = new Uint8Array(t._width * t._height * 4), n = (this._gl.readPixels(0, 0, t._width, t._height, this._gl.RGBA, this._gl.UNSIGNED_BYTE, n), 
   this._gl.bindFramebuffer(this._gl.FRAMEBUFFER, null), new ImageData(new Uint8ClampedArray(n.buffer), r.width, r.height));
   i.putImageData(n, 0, 0, 0, 0, r.width, r.height);
   (u = document.createElement("a")).download = e + ".png", u.href = r.toDataURL();
   var u, i = document.createEvent("MouseEvent");
   i.initEvent("click", !0, !0), u.dispatchEvent(i);
  }
 }
 getGLBuffer(t) {
  return this._attributeManager.getGLBuffer(t);
 }
 deleteAttributeBuffers() {
  this._attributeManager.deleteBuffers();
 }
 deleteFrameBuffers() {
  this._fboManager.deleteFrameBuffers();
 }
 deleteTextures() {
  this._textureManager.deleteTextures();
 }
 clear(t, e, i) {
  var r;
  null === this._gl.getParameter(this._gl.FRAMEBUFFER_BINDING) && (void (r = 0) !== t && !t || (r |= this._gl.COLOR_BUFFER_BIT), 
  void 0 !== e && !e || (r |= this._gl.DEPTH_BUFFER_BIT), void 0 !== i && !i || (r |= this._gl.STENCIL_BUFFER_BIT), 
  this._gl.clear(r));
 }
 get clearColor() {
  return this._clearColor;
 }
 set clearColor(t) {
  this.setClearColor(t.x, t.y, t.z, t.w);
 }
 setClearColor(t, e, i, r) {
  var s = new Vector4(t, e, i, r);
  !1 === this._clearColor.equals(s) && (this._gl.clearColor(t, e, i, r), this._clearColor.copy(s));
 }
 setClearDepth(t) {
  this._clearDepth !== t && (this._gl.clearDepth(t), this._clearDepth = t);
 }
 setClearStencil(t) {
  this._clearStencil !== t && (this._gl.clearStencil(t), this._clearStencil = t);
 }
 get context() {
  return this._gl;
 }
 get glVersion() {
  return this._glVersion;
 }
 get cache_programs() {
  return GLManager.sProgramCaching;
 }
 set cache_programs(t) {
  GLManager.sProgramCaching = t;
 }
 get gl() {
  return this._gl;
 }
 get contextAttributes() {
  return this._gl.getContextAttributes();
 }
 imageDataToImage(t) {
  var e = document.createElement("canvas"), i = e.getContext("2d"), i = (e.width = t.width, 
  e.height = t.height, i.putImageData(t, 0, 0), new Image());
  return i.src = e.toDataURL(), i;
 }
 flipImage(t, e, i) {
  for (var r = i / 2 | 0, s = 4 * e, a = new Uint8Array(4 * e), n = 0; n < r; ++n) {
   var o = n * s, h = (i - n - 1) * s;
   a.set(t.subarray(o, o + s)), t.copyWithin(o, h, h + s), t.set(a, h);
  }
 }
 openImageInNewTab(t) {
  const e = window.open(), i = this.imageDataToImage(t);
  i.addEventListener("load", function() {
   e ? e.scrollTo(i.width / 2 - e.innerWidth / 2, i.height / 2 - e.innerHeight / 2) : console.warn("Opening of a new tab failed");
  }), e ? e.document.body.appendChild(i) : console.warn("Opening of a new tab failed");
 }
}

class RendeQuTor {
 constructor(t, e, i) {
  this.renderer = t, this.scene = e, this.camera = i, this.queue = new RenderQueue(t), 
  this.pqueue = new RenderQueue(t), this.vp_w = 0, this.vp_h = 0, this.pick_radius = 32, 
  this.pick_center = 16, this.make_PRP_plain(), this.make_PRP_depth2r(), this.renderer.preDownloadPrograms([ this.PRP_depth2r_mat.requiredProgram(this.renderer) ]), 
  this.SSAA_value = 1, this.clear_zero_f32arr = new Float32Array([ 0, 0, 0, 0 ]), 
  this.std_textures = [], this.std_tex_cnt = 0, this.std_tex_used = new Set();
 }
 initDirectToScreen() {
  this.make_RP_DirectToScreen();
 }
 initSimple(t) {
  this.SSAA_value = t, this.make_RP_SSAA_Super(), this.make_RP_GBuffer(), this.make_RP_Outline(), 
  this.make_RP_GaussHVandBlend(), this.make_RP_ToScreen(), this.make_RP_ToneMapToScreen(), 
  this.RP_GBuffer.obj_list = [], this.renderer.preDownloadPrograms([ this.RP_GBuffer_mat.requiredProgram(this.renderer), this.RP_Outline_mat.requiredProgram(this.renderer), this.RP_GaussH_mat.requiredProgram(this.renderer), this.RP_Blend_mat.requiredProgram(this.renderer), this.RP_ToScreen_mat.requiredProgram(this.renderer), this.RP_ToneMapToScreen_mat.requiredProgram(this.renderer) ]);
 }
 initFull(t) {
  this.SSAA_value = t, this.make_RP_SSAA_Super(), this.make_RP_HighPassGaussBloom(), 
  this.make_RP_ToScreen(), this.RP_ToScreen.input_texture = "color_bloom";
 }
 updateViewport(t, e) {
  var i = {
   width: this.vp_w = t,
   height: this.vp_h = e
  }, r = this.queue._renderQueue;
  for (let t = 0; t < r.length; t++) r[t].view_setup(i);
 }
 pop_std_texture() {
  let t;
  return t = 0 == this.std_textures.length ? "std_tex_" + this.std_tex_cnt++ : this.std_textures.pop(), 
  this.std_tex_used.add(t), t;
 }
 push_std_texture(t) {
  this.std_tex_used.delete(t), this.std_textures.push(t);
 }
 release_std_textures() {
  if (0 < this.std_tex_used.size) {
   for (const t of this.std_tex_used) this.std_textures.push(t);
   this.std_tex_used.clear();
  }
 }
 render_outline() {
  var t = this.pop_std_texture(), e = this.pop_std_texture();
  this.RP_GBuffer.outTextures[0].id = t, this.RP_GBuffer.outTextures[1].id = e, 
  this.queue.render_pass(this.RP_GBuffer, "GBuffer"), this.RP_Outline.intex_normal = t, 
  this.RP_Outline.intex_view_dir = e, this.tex_outline ? this.RP_Outline.outTextures[0].clearColorArray = null : this.tex_outline = this.pop_std_texture(), 
  this.RP_Outline.outTextures[0].id = this.tex_outline, this.queue.render_pass(this.RP_Outline, "Outline"), 
  this.push_std_texture(t), this.push_std_texture(e);
 }
 render_main_and_blend_outline() {
  var t, e, i = 1 == this.SSAA_value, r = i ? this.pop_std_texture() : "color_main";
  this.RP_SSAA_Super.outTextures[0].id = r, this.queue.render_pass(this.RP_SSAA_Super, "SSAA Super"), 
  this.tex_outline ? (t = this.tex_outline, e = this.pop_std_texture(), this.RP_GaussH.intex = t, 
  this.RP_GaussH.outTextures[0].id = e, this.queue.render_pass(this.RP_GaussH, "GaussH"), 
  this.RP_GaussV.intex = e, this.RP_GaussV.outTextures[0].id = t, this.queue.render_pass(this.RP_GaussV, "GaussV"), 
  this.RP_Blend.intex_outline_blurred = t, this.RP_Blend.intex_main = r, this.RP_Blend.outTextures[0].id = e, 
  this.queue.render_pass(this.RP_Blend, "Blend"), i && this.push_std_texture(r), 
  this.push_std_texture(this.tex_outline), this.RP_Outline.outTextures[0].clearColorArray = this.clear_zero_f32arr, 
  this.tex_outline = null, this.tex_final = e, this.tex_final_push = !0) : (this.tex_final = r, 
  this.tex_final_push = i);
 }
 render_tone_map_to_screen() {
  this.RP_ToneMapToScreen.input_texture = this.tex_final, this.queue.render_pass(this.RP_ToneMapToScreen, "Tone Map To Screen"), 
  this.tex_final_push && (this.push_std_texture(this.tex_final), this.tex_final = null, 
  this.tex_final_push = null);
 }
 render_final_to_screen() {
  this.RP_ToScreen.input_texture = this.tex_final, this.queue.render_pass(this.RP_ToScreen, "Copy Final To Screen"), 
  this.tex_final_push && (this.push_std_texture(this.tex_final), this.tex_final = null, 
  this.tex_final_push = null);
 }
 render_begin(t) {
  this.tex_outline = null, this.queue.render_begin(t);
 }
 render_end() {
  this.queue.render_end(), this.release_std_textures();
 }
 render() {
  this.queue.render();
 }
 pick_begin(t, e) {
  this.camera.prePickStoreTBLR(), this.camera.narrowProjectionForPicking(this.vp_w, this.vp_h, this.pick_radius, this.pick_radius, t, this.vp_h - 1 - e);
 }
 pick_end() {
  this.camera.postPickRestoreTBLR();
 }
 pick(t, e, i = !1) {
  this.renderer.pick_setup(this.pick_center, this.pick_center);
  var r = this.pqueue.render();
  if (r.x = t, r.y = e, r.depth = -1, r.object = this.renderer.pickedObject3D, i && null !== this.renderer.pickedObject3D) {
   var t = this.renderer, e = t.gl, i = t.glManager._fboManager, s = (i.bindFramebuffer(this.pqueue._renderTarget), 
   new Float32Array(36)), a = (e.readBuffer(e.COLOR_ATTACHMENT0), e.readPixels(this.pick_center - 1, this.pick_center - 1, 3, 3, e.RGBA, e.FLOAT, s), 
   i.unbindFramebuffer(), this.camera.near), n = this.camera.far;
   for (let t = 0; t < 9; ++t) s[t] = a * n / ((a - n) * s[4 * t] + n);
   r.depth = s[4];
  }
  return r;
 }
 pick_instance(t) {
  return t.object !== this.renderer.pickedObject3D ? console.error("RendeQuTor::pick_instance state mismatch", t, this.renderer.pickedObject3D) : (this.renderer._pickSecondaryEnabled = !0, 
  this.pqueue.render(), t.instance = this.renderer._pickedID), t;
 }
 make_PRP_plain() {
  let i = this;
  this.PRP_plain = new RenderPass(RenderPass.BASIC, function(t, e) {}, function(t, e) {
   return {
    scene: i.scene,
    camera: i.camera
   };
  }, function(t, e) {}, RenderPass.TEXTURE, {
   width: this.pick_radius,
   height: this.pick_radius
  }, "depth_picking", [ {
   id: "color_picking",
   textureConfig: RenderPass.DEFAULT_R32UI_TEXTURE_CONFIG,
   clearColorArray: new Uint32Array([ 4294967295, 0, 0, 0 ])
  } ]), this.pqueue.pushRenderPass(this.PRP_plain);
 }
 make_PRP_depth2r() {
  this.PRP_depth2r_mat = new CustomShaderMaterial("copyDepthToRed"), this.PRP_depth2r_mat.lights = !1;
  let i = this;
  this.PRP_depth2r = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.PRP_depth2r_mat,
    textures: [ t.depth_picking ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, {
   width: this.pick_radius,
   height: this.pick_radius
  }, null, [ {
   id: "depthr32f_picking",
   textureConfig: RenderPass.FULL_FLOAT_R32F_TEXTURE_CONFIG,
   clearColorArray: new Float32Array([ 1, 0, 0, 0 ])
  } ]), this.pqueue.pushRenderPass(this.PRP_depth2r);
 }
 make_RP_DirectToScreen() {
  let i = this;
  this.RP_DirectToScreen = new RenderPass(RenderPass.BASIC, function(t, e) {}, function(t, e) {
   return {
    scene: i.scene,
    camera: i.camera
   };
  }, function(t, e) {}, RenderPass.SCREEN, null), this.RP_DirectToScreen.view_setup = function(t) {
   this.viewport = t;
  }, this.queue.pushRenderPass(this.RP_DirectToScreen);
 }
 make_RP_SSAA_Super() {
  let i = this;
  this.RP_SSAA_Super = new RenderPass(RenderPass.BASIC, function(t, e) {}, function(t, e) {
   return {
    scene: i.scene,
    camera: i.camera
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, "depth_main", [ {
   id: "color_main",
   textureConfig: RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG
  } ]), this.RP_SSAA_Super.view_setup = function(t) {
   this.viewport = {
    width: t.width * i.SSAA_value,
    height: t.height * i.SSAA_value
   };
  }, this.queue.pushRenderPass(this.RP_SSAA_Super);
 }
 make_RP_SSAA_Down() {
  this.RP_SSAA_Down_mat = new CustomShaderMaterial("copyTexture"), this.RP_SSAA_Down_mat.lights = !1;
  let i = this;
  this.RP_SSAA_Down = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_SSAA_Down_mat,
    textures: [ t[this.input_texture] ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "color_main",
   textureConfig: RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG
  } ]), this.RP_SSAA_Down.input_texture = "color_super", this.RP_SSAA_Down.view_setup = function(t) {
   this.viewport = t;
  }, this.queue.pushRenderPass(this.RP_SSAA_Down);
 }
 make_RP_ToScreen() {
  this.RP_ToScreen_mat = new CustomShaderMaterial("copyTexture"), this.RP_ToScreen_mat.lights = !1;
  let i = this;
  this.RP_ToScreen = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_ToScreen_mat,
    textures: [ t[this.input_texture] ]
   };
  }, function(t, e) {}, RenderPass.SCREEN, null), this.RP_ToScreen.input_texture = "color_main", 
  this.RP_ToScreen.view_setup = function(t) {
   this.viewport = t;
  }, this.queue.pushRenderPass(this.RP_ToScreen);
 }
 make_RP_ToneMapToScreen() {
  this.RP_ToneMapToScreen_mat = new CustomShaderMaterial("ToneMapping", {
   MODE: 1,
   gamma: 1,
   exposure: 2
  }), this.RP_ToneMapToScreen_mat.lights = !1;
  let i = this;
  this.RP_ToneMapToScreen = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_ToneMapToScreen_mat,
    textures: [ t[this.input_texture] ]
   };
  }, function(t, e) {}, RenderPass.SCREEN, null), this.RP_ToneMapToScreen.input_texture = "color_main", 
  this.RP_ToneMapToScreen.view_setup = function(t) {
   this.viewport = t;
  }, this.queue.pushRenderPass(this.RP_ToneMapToScreen);
 }
 make_RP_GBuffer() {
  this.RP_GBuffer_mat = new CustomShaderMaterial("GBufferMini"), this.RP_GBuffer_mat.lights = !1, 
  this.RP_GBuffer_mat.side = FRONT_AND_BACK_SIDE, this.RP_GBuffer_mat_flat = new CustomShaderMaterial("GBufferMini"), 
  this.RP_GBuffer_mat_flat.lights = !1, this.RP_GBuffer_mat_flat.side = FRONT_AND_BACK_SIDE, 
  this.RP_GBuffer_mat_flat.normalFlat = !0;
  let r = this;
  this.RP_GBuffer = new RenderPass(RenderPass.BASIC, function(t, e) {}, function(t, e) {
   r.renderer._outlineEnabled = !0, r.renderer._outlineArray = this.obj_list, r.renderer._defaultOutlineMat = r.RP_GBuffer_mat, 
   r.renderer._defaultOutlineMatFlat = r.RP_GBuffer_mat_flat, r.renderer._fillRequiredPrograms(r.RP_GBuffer_mat.requiredProgram(r.renderer)), 
   r.renderer._fillRequiredPrograms(r.RP_GBuffer_mat_flat.requiredProgram(r.renderer));
   for (const i of this.obj_list) i.outlineMaterial && r.renderer._fillRequiredPrograms(i.outlineMaterial.requiredProgram(r.renderer));
   return {
    scene: r.scene,
    camera: r.camera
   };
  }, function(t, e) {
   r.renderer._outlineEnabled = !1, r.renderer._outlineArray = null;
  }, RenderPass.TEXTURE, null, "depth_gbuff", [ {
   id: "normal",
   textureConfig: RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG,
   clearColorArray: this.clear_zero_f32arr
  }, {
   id: "view_dir",
   textureConfig: RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG,
   clearColorArray: this.clear_zero_f32arr
  } ]), this.RP_GBuffer.view_setup = function(t) {
   this.viewport = t;
  }, this.queue.pushRenderPass(this.RP_GBuffer);
 }
 make_RP_Outline() {
  this.RP_Outline_mat = new CustomShaderMaterial("outline", {
   scale: 1,
   edgeColor: [ 1.4, 0, .8, 1 ],
   _DepthThreshold: 6,
   _NormalThreshold: .6,
   _DepthNormalThreshold: .5,
   _DepthNormalThresholdScale: 7
  }), this.RP_Outline_mat.addSBFlag("DISCARD_NON_EDGE"), this.RP_Outline_mat.lights = !1;
  let i = this;
  this.RP_Outline = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_Outline_mat,
    textures: [ t.depth_gbuff, t[this.intex_normal], t[this.intex_view_dir] ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "color_outline",
   textureConfig: RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG,
   clearColorArray: this.clear_zero_f32arr
  } ]), this.RP_Outline.intex_normal = "normal", this.RP_Outline.intex_view_dir = "view_dir", 
  this.RP_Outline.view_setup = function(t) {
   this.viewport = t;
  }, this.queue.pushRenderPass(this.RP_Outline);
 }
 make_RP_GaussHVandBlend() {
  let i = this;
  this.RP_GaussH_mat = new CustomShaderMaterial("gaussBlur", {
   horizontal: !0,
   power: 4
  }), this.RP_GaussH_mat.lights = !1, this.RP_GaussH = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_GaussH_mat,
    textures: [ t[this.intex] ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "gauss_h",
   textureConfig: RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG
  } ]), this.RP_GaussH.intex = "color_outline", this.RP_GaussH.view_setup = function(t) {
   this.viewport = t;
  }, this.RP_GaussV_mat = new CustomShaderMaterial("gaussBlur", {
   horizontal: !1,
   power: 4
  }), this.RP_GaussV_mat.lights = !1, this.RP_GaussV = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_GaussV_mat,
    textures: [ t[this.intex] ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "gauss_hv",
   textureConfig: RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG
  } ]), this.RP_GaussV.intex = "gauss_h", this.RP_GaussV.view_setup = function(t) {
   this.viewport = t;
  }, this.RP_Blend_mat = new CustomShaderMaterial("blendingAdditive"), this.RP_Blend_mat.lights = !1, 
  this.RP_Blend = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_Blend_mat,
    textures: [ t[this.intex_outline_blurred], t[this.intex_main] ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "color_final",
   textureConfig: RenderPass.DEFAULT_RGBA16F_TEXTURE_CONFIG
  } ]), this.RP_Blend.intex_outline_blurred = "gauss_hv", this.RP_Blend.intex_main = "color_main", 
  this.RP_Blend.view_setup = function(t) {
   this.viewport = t;
  }, this.queue.pushRenderPass(this.RP_GaussH), this.queue.pushRenderPass(this.RP_GaussV), 
  this.queue.pushRenderPass(this.RP_Blend);
 }
 make_RP_HighPassGaussBloom() {
  let i = this;
  var t = new CustomShaderMaterial("highPass", {
   MODE: HIGHPASS_MODE_DIFFERENCE,
   targetColor: [ 0, 0, 1 ],
   threshold: .1
  });
  console.log("XXXXXXXX", t), this.RP_HighPass_mat = t, this.RP_HighPass_mat.lights = !1, 
  this.RP_HighPass = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_HighPass_mat,
    textures: [ t.color_ssaa_super ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "color_high_pass",
   textureConfig: RenderPass.DEFAULT_RGBA_TEXTURE_CONFIG
  } ]), this.RP_HighPass.view_setup = function(t) {
   this.viewport = {
    width: t.width * i.SSAA_value,
    height: t.height * i.SSAA_value
   };
  }, this.queue.pushRenderPass(this.RP_HighPass), this.RP_Gauss1_mat = new CustomShaderMaterial("gaussBlur", {
   horizontal: !0,
   power: 1
  }), this.RP_Gauss1_mat.lights = !1, this.RP_Gauss1 = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_Gauss1_mat,
    textures: [ t.color_high_pass ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "color_gauss_half",
   textureConfig: RenderPass.DEFAULT_RGBA_TEXTURE_CONFIG
  } ]), this.RP_Gauss1.view_setup = function(t) {
   this.viewport = {
    width: t.width * i.SSAA_value,
    height: t.height * i.SSAA_value
   };
  }, this.queue.pushRenderPass(this.RP_Gauss1), this.RP_Gauss2_mat = new CustomShaderMaterial("gaussBlur", {
   horizontal: !1,
   power: 1
  }), this.RP_Gauss2_mat.lights = !1, this.RP_Gauss2 = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_Gauss2_mat,
    textures: [ t.color_gauss_half ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "color_gauss_full",
   textureConfig: RenderPass.DEFAULT_RGBA_TEXTURE_CONFIG
  } ]), this.RP_Gauss2.view_setup = function(t) {
   this.viewport = {
    width: t.width * i.SSAA_value,
    height: t.height * i.SSAA_value
   };
  }, this.queue.pushRenderPass(this.RP_Gauss2), this.RP_Bloom_mat = new CustomShaderMaterial("bloom"), 
  this.RP_Bloom_mat.lights = !1, this.RP_Bloom = new RenderPass(RenderPass.POSTPROCESS, function(t, e) {}, function(t, e) {
   return {
    material: i.RP_Bloom_mat,
    textures: [ t.color_gauss_full, t.color_ssaa_super ]
   };
  }, function(t, e) {}, RenderPass.TEXTURE, null, null, [ {
   id: "color_bloom",
   textureConfig: RenderPass.DEFAULT_RGBA_TEXTURE_CONFIG
  } ]), this.RP_Bloom.view_setup = function(t) {
   this.viewport = {
    width: t.width * i.SSAA_value,
    height: t.height * i.SSAA_value
   };
  }, this.queue.pushRenderPass(this.RP_Bloom);
 }
}

class REveCameraControls extends EventDispatcher {
 static matrixExtendDone = !1;
 constructor(D, t) {
  var s, a, e = {
   ROTATE: 0,
   DOLLY: 1,
   PAN: 2
  }, i = {
   ROTATE: 0,
   PAN: 1,
   DOLLY_PAN: 2,
   DOLLY_ROTATE: 3
  }, n = (super(EventDispatcher), REveCameraControls.matrixExtendDone || (Matrix4.prototype.lookAtMt = function(t, e, i) {
   var r = new Vector3(), s = new Vector3(), a = new Vector3(), n = this.elements;
   return a.copy(e), a.normalize(), r.crossVectors(i, a), r.normalize(), s.crossVectors(a, r), 
   n[0] = r.x, n[4] = s.x, n[8] = a.x, n[1] = r.y, n[5] = s.y, n[9] = a.y, n[2] = r.z, 
   n[6] = s.z, n[10] = a.z, this;
  }, Matrix4.prototype.getBaseVector = function(t) {
   var t = 4 * --t, e = this.elements;
   return new Vector3(e[0 + t], e[1 + t], e[2 + t]);
  }, Matrix4.prototype.getTranslation = function() {
   var t = this.elements;
   return new Vector3(t[12], t[13], t[14]);
  }, Matrix4.prototype.setBaseVector = function(t, e, i, r) {
   var t = 4 * --t, s = this.elements;
   e.isVector3 ? (s[0 + t] = e.x, s[1 + t] = e.y, s[2 + t] = e.z) : (s[0 + t] = e, 
   s[1 + t] = i, s[2 + t] = r);
  }, Matrix4.prototype.rotateIP = function(t) {
   var e = this.elements, i = t.clone();
   t.x = e[0] * i.x + e[4] * i.y + e[8] * i.z, t.y = e[1] * i.x + e[5] * i.y + e[9] * i.z, 
   t.z = e[2] * i.x + e[6] * i.y + e[10] * i.z;
  }, Matrix4.prototype.rotateLF = function(i, r, t) {
   if (i != r) {
    var s, a, n = Math.cos(t), o = Math.sin(t), h = this.elements;
    i = 4 * (i - 1), r = 4 * (r - 1);
    let e = 0;
    for (let t = 0; t < 4; ++t, ++e) s = n * h[i + e] + o * h[r + e], a = n * h[r + e] - o * h[i + e], 
    h[i + e] = s, h[r + e] = a;
   }
  }, Matrix4.prototype.rotatePF = function(e, i, t) {
   if (e != i) {
    var r = Math.cos(t), s = Math.sin(t), a = this.elements;
    --e, --i;
    for (let t = 0; t < 4; ++t) {
     var n = 4 * t, o = r * a[e + n] - s * a[i + n], h = r * a[i + n] + s * a[e + n];
     a[e + n] = o, a[i + n] = h;
    }
   }
  }, Matrix4.prototype.moveLF = function(t, e) {
   var i = this.elements, t = 4 * (t - 1);
   i[12] += e * i[t], i[13] += e * i[1 + t], i[14] += e * i[2 + t];
  }, Matrix4.prototype.dump = function() {
   for (let i = 0; i < 4; i++) {
    let e = "[ ";
    for (let t = 0; t < 4; t++) {
     var r = this.elements[4 * t + i].toFixed(2);
     e = e + r + " ";
    }
    console.log(e + "]");
   }
  }, REveCameraControls.matrixExtendDone = !0), this.object = D, this.domElement = void 0 !== t ? t : document, 
  this.enabled = !0, this.target = new Vector3(), this.cameraCenter = new Vector3(), 
  this.minDistance = 0, this.maxDistance = 1 / 0, this.minZoom = 0, this.maxZoom = 1 / 0, 
  this.minPolarAngle = 0, this.maxPolarAngle = Math.PI, this.minAzimuthAngle = -1 / 0, 
  this.maxAzimuthAngle = 1 / 0, this.enableDamping = !1, this.dampingFactor = .05, 
  this.enableZoom = !0, this.zoomSpeed = 1, this.enableRotate = !0, this.rotateSpeed = 1, 
  this.enablePan = !0, this.panSpeed = 1, this.screenSpacePanning = !1, this.keyPanSpeed = 7, 
  this.autoRotate = !1, this.autoRotateSpeed = 2, this.enableKeys = !0, this.keys = {
   LEFT: 37,
   UP: 38,
   RIGHT: 39,
   BOTTOM: 40
  }, this.mouseButtons = {
   LEFT: e.ROTATE,
   MIDDLE: e.DOLLY,
   RIGHT: e.PAN
  }, this.touches = {
   ONE: i.ROTATE,
   TWO: i.DOLLY_PAN
  }, this.target0 = this.target.clone(), this.position0 = this.object.position.clone(), 
  this.zoom0 = this.object.zoom, this.setCamBaseMtx = function(t, e) {
   m.identity(), m.setBaseVector(1, t), m.setBaseVector(3, e);
   var i = new Vector3();
   i.crossVectors(e, t), m.setBaseVector(2, i);
  }, this.setFromBBox = function(t) {
   var e = new Vector3(), e = (t.getCenter(e), Math.max(t.min.length(), t.max.length()));
   g.identity(), this.object.isPerspectiveCamera ? (t = Math.min(30, 30 * this.object.aspect), 
   t = e / (2 * Math.tan(t * Math.PI * .8 / 180)), g.moveLF(1, t)) : (t = .625 * Math.sqrt(3) * e, 
   g.moveLF(1, t), n.object.updateProjectionMatrix());
  }, this.setCameraCenter = function(t, e, i) {
   this.cameraCenter.set(t, e, i);
   t = new Matrix4(), t.multiplyMatrices(m, g), m.setBaseVector(4, this.cameraCenter), 
   e = m.clone();
   e.getInverse(m), g.multiplyMatrices(e, t), this.centerMarker && (this.centerMarker.position = this.cameraCenter, 
   this.centerMarker.visible = !0, this.centerMarker.updateMatrix());
  }, this.getPolarAngle = function() {
   return c.phi;
  }, this.getAzimuthalAngle = function() {
   return c.theta;
  }, this.saveState = function() {
   n.target0.copy(n.target), n.position0.copy(n.object.position), n.zoom0 = n.object.zoom;
  }, this.reset = function() {
   n.target.copy(n.target0), n.object.position.copy(n.position0), n.object.zoom = n.zoom0, 
   n.object.updateProjectionMatrix(), n.dispatchEvent(o), n.update(), l = u.NONE;
  }, this.resetOrthoPanZoom = function() {
   f.set(0, 0, 0), n.object.zoom = .78, n.object.updateProjectionMatrix(), y = !0;
  }, this.resetMouseDown = function(t) {
   N();
  }, this.testCameraMenu = function() {
   L(.5);
  }, this.update = (s = new Vector3(), a = new Quaternion(), function() {
   1 != p && (e = g.getBaseVector(1), t = g.getBaseVector(4), e = e.dot(t), e = Math.sqrt(e), 
   t.multiplyScalar(p), g.setBaseVector(4, t), p = 1, n.object.near = Math.min(.1 * e, 20)), 
   (f.x || f.y) && (g.moveLF(2, f.x), g.moveLF(3, f.y), f.set(0, 0, 0));
   var t = new Matrix4(), e = (t.multiplyMatrices(m, g), n.object.testMtx = t, new Vector3()), i = (e.setFromMatrixPosition(t), 
   new Vector3()), r = (i.setFromMatrixColumn(t, 0), new Vector3());
   return r.setFromMatrixColumn(t, 2), n.object._matrix.lookAtMt(e, i, r), n.object._matrix.setPosition(e), 
   n.object.matrixWorld.copy(n.object.matrix), y || s.distanceToSquared(t.getBaseVector(4)) > _ || 10 * (d.phi + d.theta) > _ ? (n.dispatchEvent(o), 
   s.copy(t.getBaseVector(4)), a.copy(n.object.quaternion), y = !1, d.theta = 0, 
   !(d.phi = 0)) : (s.distanceToSquared(t.getBaseVector(4)), !0);
  }), this.dispose = function() {
   n.domElement.removeEventListener("contextmenu", K, !1), n.domElement.removeEventListener("mousedown", j, !1), 
   n.domElement.removeEventListener("wheel", H, !1), n.domElement.removeEventListener("touchstart", X, !1), 
   n.domElement.removeEventListener("touchend", Z, !1), n.domElement.removeEventListener("touchmove", Y, !1), 
   document.removeEventListener("mousemove", I, !1), document.removeEventListener("mouseup", N, !1), 
   window.removeEventListener("keydown", O, !1);
  }, this), o = {
   type: "change"
  }, r = {
   type: "start"
  }, h = {
   type: "end"
  }, u = {
   NONE: -1,
   ROTATE: 0,
   DOLLY: 1,
   PAN: 2,
   TOUCH_ROTATE: 3,
   TOUCH_PAN: 4,
   TOUCH_DOLLY_PAN: 5,
   TOUCH_DOLLY_ROTATE: 6
  }, l = u.NONE, _ = 1e-6, c = new Spherical(), d = new Spherical(), m = new Matrix4(), g = new Matrix4(), p = 1, f = new Vector3(), y = !1, T = new Vector2(), x = new Vector2(), S = new Vector2(), E = new Vector2(), A = new Vector2(), R = new Vector2(), v = new Vector2(), P = new Vector2(), w = new Vector2();
  function M() {
   return Math.pow(.95, n.zoomSpeed);
  }
  function B(t, e) {
   var i, r, s, a;
   0 != t && (a = g.getBaseVector(1), g.getBaseVector(2), s = g.getBaseVector(3), 
   i = (r = g.getTranslation()).dot(a), r = r.dot(s), s = m.getBaseVector(3), m.rotateIP(a), 
   (a = Math.acos(a.dot(s))) + t < .01 ? t = .01 - a : a + t > Math.PI - .01 && (t = Math.PI - .01 - a), 
   g.moveLF(1, -i), g.moveLF(3, -r), g.rotateLF(3, 1, t), g.moveLF(3, r), g.moveLF(1, i)), 
   0 != e && g.rotatePF(1, 2, -e), d.phi = t, d.theta = e;
  }
  new Vector3();
  var b = function(t, e) {
   t = -t;
   var i, r, s = n.domElement === document ? n.domElement.body : n.domElement;
   n.object.isPerspectiveCamera ? (i = e * (r = .5 * (n.object.far + n.object.near) * Math.tan(.5 * n.object.fov * Math.PI / 180)) / s.clientHeight, 
   r = t * r / s.clientHeight, f.setX(r), f.setY(i)) : n.object.isOrthographicCamera ? (f.setX(t * (n.object.right - n.object.left) / n.object.zoom / s.clientWidth), 
   f.setY(e * (n.object.top - n.object.bottom) / n.object.zoom / s.clientHeight)) : (console.warn("WARNING: REveCameraControls encountered an unknown camera type - pan disabled."), 
   n.enablePan = !1), n.update();
  };
  function L(t) {
   n.object.isPerspectiveCamera ? p /= t : n.object.isOrthographicCamera ? (n.object.zoom = Math.max(n.minZoom, Math.min(n.maxZoom, n.object.zoom * t)), 
   n.object.updateProjectionMatrix(), y = !0) : (console.warn("WARNING: REveCameraControls encountered an unknown camera type - dolly/zoom disabled."), 
   n.enableZoom = !1), n.update();
  }
  function z(t) {
   n.object.isPerspectiveCamera ? p *= t : n.object.isOrthographicCamera ? (n.object.zoom = Math.max(n.minZoom, Math.min(n.maxZoom, n.object.zoom / t)), 
   n.object.updateProjectionMatrix(), y = !0) : (console.warn("WARNING: REveCameraControls encountered an unknown camera type - dolly/zoom disabled."), 
   n.enableZoom = !1), n.update();
  }
  function C(t) {
   T.set(t.clientX, t.clientY);
  }
  function F(t) {
   E.set(t.clientX, t.clientY);
  }
  function U(t) {
   var e;
   1 == t.touches.length ? T.set(t.touches[0].pageX, t.touches[0].pageY) : (e = .5 * (t.touches[0].pageX + t.touches[1].pageX), 
   t = .5 * (t.touches[0].pageY + t.touches[1].pageY), T.set(e, t));
  }
  function G(t) {
   var e;
   1 == t.touches.length ? E.set(t.touches[0].pageX, t.touches[0].pageY) : (e = .5 * (t.touches[0].pageX + t.touches[1].pageX), 
   t = .5 * (t.touches[0].pageY + t.touches[1].pageY), E.set(e, t));
  }
  function V(t) {
   var e = t.touches[0].pageX - t.touches[1].pageX, t = t.touches[0].pageY - t.touches[1].pageY, e = Math.sqrt(e * e + t * t);
   v.set(0, e);
  }
  function k(t) {
   1 == t.touches.length ? x.set(t.touches[0].pageX, t.touches[0].pageY) : (e = .5 * (t.touches[0].pageX + t.touches[1].pageX), 
   t = .5 * (t.touches[0].pageY + t.touches[1].pageY), x.set(e, t)), S.subVectors(x, T).multiplyScalar(n.rotateSpeed);
   var e = n.domElement === document ? n.domElement.body : n.domElement;
   B(-2 * Math.PI * S.y / e.clientHeight, 2 * Math.PI * S.x / e.clientWidth), T.copy(x);
  }
  function q(t) {
   var e;
   1 == t.touches.length ? A.set(t.touches[0].pageX, t.touches[0].pageY) : (e = .5 * (t.touches[0].pageX + t.touches[1].pageX), 
   t = .5 * (t.touches[0].pageY + t.touches[1].pageY), A.set(e, t)), R.subVectors(A, E).multiplyScalar(n.panSpeed), 
   b(R.x, R.y), E.copy(A);
  }
  function W(t) {
   var e = t.touches[0].pageX - t.touches[1].pageX, t = t.touches[0].pageY - t.touches[1].pageY, e = Math.sqrt(e * e + t * t);
   P.set(0, e), w.set(0, Math.pow(P.y / v.y, n.zoomSpeed)), L(w.y), v.copy(P);
  }
  function j(t) {
   if (!1 !== n.enabled) {
    switch (t.preventDefault(), (n.domElement.focus ? n.domElement : window).focus(), 
    t.button) {
    case 0:
     switch (n.mouseButtons.LEFT) {
     case e.ROTATE:
      if (t.ctrlKey || t.metaKey || t.shiftKey) {
       if (!1 === n.enablePan) return;
       F(t), l = u.PAN;
      } else {
       if (!1 === n.enableRotate) return;
       C(t), l = u.ROTATE;
      }
      break;

     case e.PAN:
      if (t.ctrlKey || t.metaKey || t.shiftKey) {
       if (!1 === n.enableRotate) return;
       C(t), l = u.ROTATE;
      } else {
       if (!1 === n.enablePan) return;
       F(t), l = u.PAN;
      }
      break;

     default:
      l = u.NONE;
     }
     break;

    case 1:
     if (n.mouseButtons.MIDDLE === e.DOLLY) {
      if (!1 === n.enableZoom) return;
      v.set(t.clientX, t.clientY), l = u.DOLLY;
     } else l = u.NONE;
     break;

    case 2:
     switch (n.mouseButtons.RIGHT) {
     case e.ROTATE:
      if (!1 === n.enableRotate) return;
      C(t), l = u.ROTATE;
      break;

     case e.PAN:
      if (!1 === n.enablePan) return;
      F(t), l = u.PAN;
      break;

     default:
      l = u.NONE;
     }
    }
    l !== u.NONE && (document.addEventListener("mousemove", I, !1), document.addEventListener("mouseup", N, !1), 
    n.dispatchEvent(r));
   }
  }
  function I(t) {
   var e;
   if (!1 !== n.enabled) switch (t.preventDefault(), l) {
   case u.ROTATE:
    !1 !== n.enableRotate && (e = t, x.set(e.clientX, e.clientY), S.subVectors(x, T).multiplyScalar(n.rotateSpeed), 
    e = n.domElement === document ? n.domElement.body : n.domElement, B(-2 * Math.PI * S.y / e.clientHeight, 2 * Math.PI * S.x / e.clientWidth), 
    T.copy(x), n.update());
    break;

   case u.DOLLY:
    !1 !== n.enableZoom && (P.set(t.clientX, t.clientY), w.subVectors(P, v), 0 < w.y ? L(M()) : w.y < 0 && z(M()), 
    v.copy(P), n.update());
    break;

   case u.PAN:
    !1 !== n.enablePan && (A.set(t.clientX, t.clientY), R.subVectors(A, E).multiplyScalar(n.panSpeed), 
    b(R.x, R.y), E.copy(A), n.update());
   }
  }
  function N(t) {
   !1 !== n.enabled && (document.removeEventListener("mousemove", I, !1), document.removeEventListener("mouseup", N, !1), 
   n.dispatchEvent(h), l = u.NONE);
  }
  function H(t) {
   !1 === n.enabled || !1 === n.enableZoom || l !== u.NONE && l !== u.ROTATE || (t.preventDefault(), 
   t.stopPropagation(), n.dispatchEvent(r), (t = t).deltaY < 0 ? z(M()) : 0 < t.deltaY && L(M()), 
   n.update(), n.dispatchEvent(h));
  }
  function O(t) {
   if (!1 !== n.enabled && !1 !== n.enableKeys && !1 !== n.enablePan) {
    var e = !1;
    switch (t.keyCode) {
    case n.keys.UP:
     b(0, n.keyPanSpeed), e = !0;
     break;

    case n.keys.BOTTOM:
     b(0, -n.keyPanSpeed), e = !0;
     break;

    case n.keys.LEFT:
     b(n.keyPanSpeed, 0), e = !0;
     break;

    case n.keys.RIGHT:
     b(-n.keyPanSpeed, 0), e = !0;
    }
    e && (t.preventDefault(), t.stopImmediatePropagation(), n.update());
   }
  }
  function X(t) {
   if (!1 !== n.enabled) {
    switch (t.preventDefault(), t.touches.length) {
    case 1:
     switch (n.touches.ONE) {
     case i.ROTATE:
      if (!1 === n.enableRotate) return;
      U(t), l = u.TOUCH_ROTATE;
      break;

     case i.PAN:
      if (!1 === n.enablePan) return;
      G(t), l = u.TOUCH_PAN;
      break;

     default:
      l = u.NONE;
     }
     break;

    case 2:
     switch (n.touches.TWO) {
     case i.DOLLY_PAN:
      if (!1 === n.enableZoom && !1 === n.enablePan) return;
      e = t, n.enableZoom && V(e), n.enablePan && G(e), l = u.TOUCH_DOLLY_PAN;
      break;

     case i.DOLLY_ROTATE:
      if (!1 === n.enableZoom && !1 === n.enableRotate) return;
      e = t, n.enableZoom && V(e), n.enableRotate && U(e), l = u.TOUCH_DOLLY_ROTATE;
      break;

     default:
      l = u.NONE;
     }
     break;

    default:
     l = u.NONE;
    }
    var e;
    l !== u.NONE && n.dispatchEvent(r);
   }
  }
  function Y(t) {
   var e;
   if (!1 !== n.enabled) switch (t.preventDefault(), t.stopPropagation(), l) {
   case u.TOUCH_ROTATE:
    !1 !== n.enableRotate && (k(t), n.update());
    break;

   case u.TOUCH_PAN:
    !1 !== n.enablePan && (q(t), n.update());
    break;

   case u.TOUCH_DOLLY_PAN:
    !1 === n.enableZoom && !1 === n.enablePan || (e = t, n.enableZoom && W(e), n.enablePan && q(e), 
    n.update());
    break;

   case u.TOUCH_DOLLY_ROTATE:
    !1 === n.enableZoom && !1 === n.enableRotate || (e = t, n.enableZoom && W(e), 
    n.enableRotate && k(e), n.update());
    break;

   default:
    l = u.NONE;
   }
  }
  function Z(t) {
   !1 !== n.enabled && (n.dispatchEvent(h), l = u.NONE);
  }
  function K(t) {
   !1 !== n.enabled && t.preventDefault();
  }
  n.domElement.addEventListener("contextmenu", K, !1), n.domElement.addEventListener("mousedown", j, !1), 
  n.domElement.addEventListener("wheel", H, !1), n.domElement.addEventListener("touchstart", X, !1), 
  n.domElement.addEventListener("touchend", Z, !1), n.domElement.addEventListener("touchmove", Y, !1), 
  n.domElement.addEventListener("mouseenter", function(t) {
   window.addEventListener("keydown", O);
  }), n.domElement.addEventListener("mouseleave", function(t) {
   window.removeEventListener("keydown", O);
  }), this.update();
 }
}

export {
 AmbientLight,
 BACK_SIDE,
 BLACKLIST,
 Box2,
 Box3,
 BufferAttribute,
 Cache,
 Camera,
 Canvas,
 Circle,
 Color,
 Cube,
 CubeTexture,
 CustomShaderMaterial,
 Cylindrical,
 DirectionalLight,
 Euler,
 EventDispatcher,
 FRAGMENT_SHADER,
 FRONT_AND_BACK_SIDE,
 FRONT_SIDE,
 FUNC_ALWAYS,
 FUNC_EQUAL,
 FUNC_GEQUAL,
 FUNC_GREATER,
 FUNC_LEQUAL,
 FUNC_LESS,
 FUNC_NEVER,
 FUNC_NOTEQUAL,
 FlatShading,
 Float32Attribute,
 Float64Attribute,
 Frustum,
 GLAttributeManager,
 GLFrameBufferManager,
 GLManager,
 GLProgram,
 GLProgramManager,
 GLTextureManager,
 Geometry,
 GouraudShading,
 Grid,
 Group,
 HIGHPASS_MODE_BRIGHTNESS,
 HIGHPASS_MODE_DIFFERENCE,
 ImageCache,
 ImageLoader,
 Int16Attribute,
 Int32Attribute,
 Int8Attribute,
 LINES,
 LINE_LOOP,
 LINE_STRIP,
 Light,
 Line,
 Line3,
 LoadingManager,
 MAXVEC,
 MINVEC,
 Material,
 MaterialProgramTemplate,
 Matrix3,
 Matrix4,
 Mesh,
 MeshBasicMaterial,
 MeshLambertMaterial,
 MeshPhongMaterial$1 as MeshPhongMaterial,
 MeshRenderer,
 Object3D,
 OrthographicCamera,
 POINTS,
 PerspectiveCamera,
 PhongShading,
 PickingShaderMaterial,
 Plane,
 Point,
 PointBasicMaterial,
 PointLight,
 Quad,
 Quaternion,
 REveCameraControls,
 Ray,
 Raycaster,
 RendeQuTor,
 RenderArray,
 RenderArrayManager,
 RenderPass,
 RenderQueue,
 RenderTarget,
 Renderer,
 SPRITE_SPACE_SCREEN,
 SPRITE_SPACE_WORLD,
 STRIPE_CAP_BUTT,
 STRIPE_CAP_DEFAULT,
 STRIPE_CAP_ROUND,
 STRIPE_CAP_SQUARE,
 STRIPE_JOIN_BEVEL,
 STRIPE_JOIN_DEFAULT,
 STRIPE_JOIN_MITER,
 STRIPE_JOIN_ROUND,
 STRIPE_SPACE_SCREEN,
 STRIPE_SPACE_WORLD,
 SUPPRESS_DEFAULT_KEYBOARD_KEYS,
 Scene,
 ShaderBuilder,
 ShaderLoader,
 SmoothShading,
 Sphere,
 Spherical,
 SpotLight,
 Sprite,
 SpriteBasicMaterial,
 SpriteGeometry,
 Stripe,
 StripeBasicMaterial,
 Stripes,
 StripesBasicMaterial,
 StripesGeometry,
 TEXT2D_SPACE_SCREEN,
 TEXT2D_SPACE_WORLD,
 TRIANGLES,
 TRIANGLE_FAN,
 TRIANGLE_STRIP,
 Text2D,
 Text2DMaterial,
 Texture,
 TextureCache,
 Triangle,
 Uint16Attribute,
 Uint32Attribute,
 Uint8Attribute,
 Uint8ClampedAttribute,
 UpdateListener,
 VERTEX_SHADER,
 Vector2,
 Vector3,
 Vector4,
 WEBGL1,
 WEBGL2,
 WrapAroundEnding,
 XHRLoader,
 ZSprite,
 ZSpriteBasicMaterial,
 ZeroCurvatureEnding,
 ZeroSlopeEnding,
 _Math,
 gamepadIDRegex,
 revision,
 singleton,
 singletonEnforcer
};