from django.shortcuts import render

from driver_api.models import Command, Param
from driver_api.serializers import CommandSerializer, ParamSerializer
from django.http import Http404
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework import generics

class SensorList(generics.ListCreateAPIView):
    queryset = Param.objects.filter(device_type="SENSOR", param_type="ACTUAL").all()
    serializer_class = ParamSerializer


class StateList(generics.ListCreateAPIView):
    queryset = Param.objects.filter(param_type="STATE").all()
    serializer_class = ParamSerializer

class ParamList(generics.ListCreateAPIView):
    queryset = Param.objects.filter(device_type="ACTOR", param_type="NOMINAL").all()
    serializer_class = ParamSerializer
    # """
    # List all snippets, or create a new snippet.
    # """
    # def get(self, request, format=None):
    #     snippets = Param.objects.all()
    #     serializer = ParamSerializer(snippets, many=True)
    #     return Response(serializer.data)

    # def post(self, request, format=None):
    #     serializer = ParamSerializer(data=request.data)
    #     if serializer.is_valid():
    #         serializer.save()
    #         return Response(serializer.data, status=status.HTTP_201_CREATED)
    #     return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class ParamDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Param.objects.all()
    serializer_class = ParamSerializer
    lookup_field = "param_id"

class CommandDetail(generics.RetrieveUpdateAPIView):
    queryset = Command.objects.filter()
    serializer_class = CommandSerializer
    lookup_field = "command_id"
