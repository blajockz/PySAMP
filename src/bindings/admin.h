#ifndef admin_h
#define admin_h

#include <Python.h>
#include "sampgdk.h"



/* Return the number of arguments of the application command line */
static PyObject* admin_kick(PyObject *self, PyObject *args)
{
	int playerid;
	if (!PyArg_ParseTuple(args, "i:Kick", &playerid)) {
		PyErr_Print();
		return NULL;
	}
	Kick(playerid);
	Py_RETURN_TRUE;
}

static PyObject* admin_ban(PyObject *self, PyObject *args)
{
	int playerid;
	if (!PyArg_ParseTuple(args, "i:Ban", &playerid)) {
		PyErr_Print();
		return NULL;
	}
	Ban(playerid);
	Py_RETURN_TRUE;
}

static PyObject* admin_IsPlayerAdmin(PyObject *self, PyObject *args) {
	int playerid;
	if (!PyArg_ParseTuple(args, "i:IsPlayerAdmin", &playerid)) {
		PyErr_Print();
		return NULL;
	}	
	return (IsPlayerAdmin(playerid)) ? Py_True : Py_False;
}


static PyObject* admin_SendRconCommand(PyObject *self, PyObject *args) {
	const char* txt;
	sampgdk::logprintf("SendRconCommand1");
	if (!PyArg_ParseTuple(args, "s:SendRconCommand", &txt)) {
		PyErr_Print();
		return NULL;
	}
	sampgdk::logprintf("SendRconCommand");
	SendRconCommand(txt);
	Py_RETURN_TRUE;
}

static PyMethodDef AdminMethods[] = {
	{ "Kick", admin_kick, METH_VARARGS, NULL},
	{ "Ban", admin_ban, METH_VARARGS, NULL },
	{ "IsPlayerAdmin", admin_IsPlayerAdmin, METH_VARARGS, NULL },
	{ "SendRconCommand", admin_SendRconCommand, METH_VARARGS, NULL },
	{ NULL, NULL, 0, NULL }
};

static PyModuleDef AdminModule = {
	PyModuleDef_HEAD_INIT, "admin", "SAMP Admin functions", -1, AdminMethods,
	NULL, NULL, NULL, NULL
};

static PyObject* PyInit_admin()
{
	return PyModule_Create(&AdminModule);
}

#endif // !admin_h
