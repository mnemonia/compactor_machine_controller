from driver_api.models import Param
from driver_api.serializers import ParamSerializer
from django.http import Http404
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework import generics


class ParamList(generics.ListCreateAPIView):
    queryset = Param.objects.all()
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
